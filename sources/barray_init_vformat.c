#include <stdbool.h>
#include <unistd.h>
#include "ft_barray.h"
#include "ft_ctype.h"
#include "ft_math.h"
#include "ft_string.h"

enum
{
    PF_Minus = 1 << 0,
    PF_Zero = 1 << 1,
    PF_Plus = 1 << 2,
    PF_Space = 1 << 3,
    PF_Sharp = 1 << 4,
    PF_Precision = 1 << 5,
    PF_LengthL = 1 << 6,
    PF_LengthLL = 1 << 7,
    PF_LengthH = 1 << 8,
    PF_LengthHH = 1 << 9,
    PF_LengthZ = 1 << 10,
    PF_LengthJ = 1 << 11,
    PF_LengthT = 1 << 12,
    PF_LengthMask = PF_LengthL | PF_LengthLL | PF_LengthH | PF_LengthHH | PF_LengthZ | PF_LengthJ | PF_LengthT,
};

typedef struct ParseFormat_
{
    unsigned int flags;
    int width;
    int precision;
    int specifier;
}
ParseFormat;

static intmax_t va_load_i(ParseFormat *pf, va_list ap)
{
    if (pf->flags & PF_LengthZ)  return va_arg(ap, ssize_t);
    if (pf->flags & PF_LengthJ)  return va_arg(ap, intmax_t);
    if (pf->flags & PF_LengthLL) return va_arg(ap, long long);
    if (pf->flags & PF_LengthL)  return va_arg(ap, long);

    int val = va_arg(ap, int);

    if (pf->flags & PF_LengthHH) return (char)val;
    if (pf->flags & PF_LengthH)  return (short)val;

    return val;
}

static uintmax_t va_load_u(ParseFormat *pf, va_list ap)
{
    if (pf->flags & PF_LengthZ)  return va_arg(ap, size_t);
    if (pf->flags & PF_LengthJ)  return va_arg(ap, uintmax_t);
    if (pf->flags & PF_LengthLL) return va_arg(ap, unsigned long long);
    if (pf->flags & PF_LengthL)  return va_arg(ap, unsigned long);

    unsigned int val = va_arg(ap, unsigned int);

    if (pf->flags & PF_LengthHH) return (unsigned char)val;
    if (pf->flags & PF_LengthH)  return (unsigned short)val;

    return val;
}

static void ultoa_buf(unsigned char **ptr, uintmax_t value, uintmax_t base)
{
    do
    {
        unsigned char byte = value % base;

        value /= base;
        **ptr = (byte < 10) ? byte + '0' : byte + 'a' - 10;
        --(*ptr);
    }
    while (value);
}

static void get_uint(ByteArray *dst, uintmax_t value, uintmax_t base)
{
    unsigned char *ptr = (unsigned char *)dst->data + 63;

    ultoa_buf(&ptr, value, base);

    size_t size = ((unsigned char *)dst->data + 63 - ptr);
    ft_memcpy(dst->data, ptr + 1, size);
    dst->size = size;
}

static int int_set_precision(ByteArray *dst, ParseFormat *pf)
{
    pf->flags &= ~PF_Zero;

    if (pf->precision == 0 && dst->data[0] == '0')
    {
        barray_clear(dst);
        return 0;
    }

    size_t size = dst->size + (!!(pf->flags & PF_Sharp) && pf->specifier == 'o');

    if (size > (size_t)pf->precision)
        return 0;

    return barray_fill_front(dst, '0', (size_t)pf->precision - size);
}

static int int_sharp(ByteArray *dst, ParseFormat *pf)
{
    if (dst->size == 0 && pf->specifier == 'o')
        return barray_push_back(dst, '0');

    if (pf->specifier != 'p' && (dst->size == 0 || (*dst->data == '0' && dst->size == 1)))
        return 0;

    return (pf->specifier == 'o') ? barray_push_front(dst, '0') : barray_push_front_range(dst, "0x", 2);
}

static int int_zero_padding(ByteArray *dst, ParseFormat *pf, bool negative)
{
    int paddingSize = pf->width - (int)dst->size;

    pf->flags &= ~PF_Zero;

    if (pf->flags & PF_Sharp)
    {
        if (pf->specifier == 'o')
            paddingSize -= 1;

        else if (pf->specifier == 'x' || pf->specifier == 'X')
            paddingSize -= 2;
    }

    paddingSize -= !!(pf->flags & (PF_Plus | PF_Space)) || negative;

    if (paddingSize <= 0)
        return 0;

    return barray_fill_front(dst, '0', (size_t)paddingSize);
}

static int print_bin(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    uintmax_t value = va_load_u(pf, ap);

    get_uint(dst, value, 2);

    if (pf->flags & PF_Precision)
        if (int_set_precision(dst, pf))
            return -1;

    if (pf->flags & PF_Zero)
        if (int_zero_padding(dst, pf, false))
            return -1;

    return 0;
}

static int print_chr(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    (void)pf;
    barray_push_back(dst, va_arg(ap, int));
    return 0;
}

static int print_hex(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    uintmax_t value = va_load_u(pf, ap);

    get_uint(dst, value, 16);

    if (pf->flags & PF_Precision)
        if (int_set_precision(dst, pf))
            return -1;

    if (pf->flags & PF_Zero)
        if (int_zero_padding(dst, pf, false))
            return -1;

    if (pf->flags & PF_Sharp)
        if (int_sharp(dst, pf))
            return -1;

    if (pf->specifier == 'X')
        for (size_t i = 0; i < dst->size; ++i)
            dst->data[i] = ft_toupper(dst->data[i]);

    return 0;
}

static int print_int(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    intmax_t value = va_load_i(pf, ap);

    get_uint(dst, value < 0 ? -value : value, 10);

    if (pf->flags & PF_Precision)
        if (int_set_precision(dst, pf))
            return -1;

    if (pf->flags & PF_Zero)
        if (int_zero_padding(dst, pf, value < 0))
            return -1;

    if (value < 0)
        return barray_push_front(dst, '-');

    else if (pf->flags & PF_Plus)
        return barray_push_front(dst, '+');

    else
        return (pf->flags & PF_Space) ? barray_push_front(dst, ' ') : 0;
}

static int print_oct(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    uintmax_t value = va_load_u(pf, ap);

    get_uint(dst, value, 8);

    if (pf->flags & PF_Precision)
        if (int_set_precision(dst, pf))
            return -1;

    if (pf->flags & PF_Zero)
        if (int_zero_padding(dst, pf, false))
            return -1;

    if (pf->flags & PF_Sharp)
        if (int_sharp(dst, pf))
            return -1;

    return 0;
}

static int print_str(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    const char *str = va_arg(ap, char *);

    if (str == NULL)
        str = "(null)";

    size_t size = (pf->flags & PF_Precision) ? ft_strnlen(str, pf->precision) : ft_strlen(str);

    return barray_push_back_range(dst, str, size);
}

static int print_uns(ByteArray *dst, ParseFormat *pf, va_list ap)
{
    uintmax_t value = va_load_u(pf, ap);

    get_uint(dst, value, 10);

    if (pf->flags & PF_Precision)
        if (int_set_precision(dst, pf))
            return -1;

    if (pf->flags & PF_Zero)
        if (int_zero_padding(dst, pf, false))
            return -1;

    return 0;
}

static int (*const FORMAT_TABLE[58])(ByteArray *, ParseFormat *, va_list) =
{
    NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, &print_hex, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, &print_bin, &print_chr, &print_int, NULL,
    NULL, NULL, NULL, &print_int, NULL,
    NULL, NULL, NULL, NULL, &print_oct,
    &print_hex, NULL, NULL, &print_str, NULL,
    &print_uns, NULL, NULL, &print_hex, NULL, NULL
};

static const char *print_conv(ByteArray *b, const char *fmt, va_list ap)
{
    ParseFormat pf;
    ByteArray conversion;

    barray_init(&conversion);
    if (barray_reserve(&conversion, 64))
        return NULL;

    // Get the conversion flags
    pf.flags = 0;
    while (1)
    {
        if      (*fmt == '0') pf.flags |= PF_Zero;
        else if (*fmt == '+') pf.flags |= PF_Plus;
        else if (*fmt == '-') pf.flags |= PF_Minus;
        else if (*fmt == ' ') pf.flags |= PF_Space;
        else if (*fmt == '#') pf.flags |= PF_Sharp;
        else                  break;

        ++fmt;
    }

    // Get the conversion width
    if (*fmt == '*')
    {
        ++fmt;
        pf.width = va_arg(ap, int);
    }
    else
        for (pf.width = 0; ft_isdigit(*fmt); ++fmt)
            pf.width = pf.width * 10 + *fmt - '0';

    // Get the conversion precision
    if (*fmt == '-')
    {
        pf.flags |= PF_Precision;
        if (*fmt == '*')
        {
            ++fmt;
            pf.precision = va_arg(ap, int);
        }
        else
            for (pf.precision = 0; ft_isdigit(*fmt); ++fmt)
                pf.precision = pf.precision * 10 + *fmt - '0';
    }
    else
        pf.precision = 0;

    // Get the conversion length
    while (1)
    {
        if      (*fmt == 'h' && (pf.flags & PF_LengthH)) pf.flags |= PF_LengthHH;
        else if (*fmt == 'h')                            pf.flags |= PF_LengthH;
        else if (*fmt == 'l' && (pf.flags & PF_LengthL)) pf.flags |= PF_LengthLL;
        else if (*fmt == 'l')                            pf.flags |= PF_LengthL;
        else if (*fmt == 'j')                            pf.flags |= PF_LengthJ;
        else if (*fmt == 't')                            pf.flags |= PF_LengthT;
        else if (*fmt == 'z')                            pf.flags |= PF_LengthZ;
        else                                             break ;

        ++fmt;
    }
    pf.specifier = *fmt;

    // Apply some format rules to add/remove flags
    if (pf.width < 0)
    {
        pf.width = -pf.width;
        pf.flags |= PF_Minus;
    }

    if (pf.flags & PF_Minus)
        pf.flags &= ~PF_Zero;

    if (pf.flags & PF_Plus)
        pf.flags &= ~PF_Space;

    if (ft_strchrnul("cdisu", pf.specifier))
        pf.flags &= ~PF_Sharp;

    if (ft_strchrnul("uoxX", pf.specifier))
        pf.flags &= ~(PF_Space | PF_Plus);

    if (ft_strchrnul("DOU", pf.specifier))
    {
        pf.specifier += 'a' - 'A';
        pf.flags = (pf.flags & ~PF_LengthMask) | PF_LengthL;
    }

    if (pf.specifier == 'p')
        pf.flags = (pf.flags & ~PF_LengthMask) | PF_LengthL | PF_Sharp;

    if (pf.precision < 0)
        pf.flags &= ~PF_Precision;

    fmt += !!*fmt;

    if (pf.specifier < 'A' || pf.specifier > 'z' || FORMAT_TABLE[pf.specifier - 'A'] == NULL)
    {
        if (pf.specifier != '\0' && barray_push_back(&conversion, pf.specifier))
        {
            barray_destroy(&conversion);
            return NULL;
        }
    }
    else if (FORMAT_TABLE[pf.specifier - 'A'](&conversion, &pf, ap))
    {
        barray_destroy(&conversion);
        return NULL;
    }

    // Apply width and store the conversion in the main bytearray.
    const size_t conversionSize = conversion.size;
    char fillerByte = (pf.flags & PF_Zero) ? '0' : ' ';

    if (barray_push_back_range(b, conversion.data, conversionSize))
    {
        barray_destroy(&conversion);
        return NULL;
    }
    barray_destroy(&conversion);
    if (conversionSize < (size_t)pf.width)
    {
        if (pf.flags & PF_Minus)
        {
            if (barray_fill_back(b, fillerByte, (size_t)pf.width - conversionSize))
                return NULL;
        }
        else if (barray_fill(b, b->size - conversionSize, fillerByte, (size_t)pf.width - conversionSize))
            return NULL;
    }

    return fmt;
}

int barray_init_vformat(ByteArray *b, const char *fmt, va_list ap)
{
    barray_init(b);

    while (*fmt)
    {
        const char *percent = ft_strchr(fmt, '%');

        if (percent != NULL)
        {
            if (barray_push_back_range(b, fmt, percent - fmt))
            {
                barray_destroy(b);
                return -1;
            }

            fmt = print_conv(b, percent + 1, ap);

            if (fmt == NULL)
            {
                barray_destroy(b);
                return -1;
            }
        }
        else
        {
            if (barray_push_back_range(b, fmt, ft_strlen(fmt)))
            {
                barray_destroy(b);
                return -1;
            }
            break ;
        }
    }
    return 0;
}
