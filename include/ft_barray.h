#ifndef FT_BARRAY_H
# define FT_BARRAY_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define BARRAY_MIN_BYTE_ALLOC 16

typedef struct ByteArray_
{
    uint8_t *data;
    size_t size;
    size_t maxSize;
}
ByteArray;

int ft_bauto_expand(ByteArray *b);
size_t ft_bcapacity(const ByteArray *b);
void ft_bclear(ByteArray *b);
void ft_bdestroy(ByteArray *b);
void ft_berase(ByteArray *b, size_t index);
void ft_berase_range(ByteArray *b, size_t start, size_t end);
int ft_bfill(ByteArray *b, size_t index, char c, size_t size);
int ft_bfill_back(ByteArray *b, char c, size_t size);
int ft_bfill_front(ByteArray *b, char c, size_t size);
void ft_binit(ByteArray *b);
void ft_binit_buffer(ByteArray *b, void *data, size_t size);
int ft_binit_cbuffer(ByteArray *b, const void *data, size_t size);
int ft_binit_cstr(ByteArray *b, const char *str);
int ft_binit_format(ByteArray *b, const char *fmt, ...);
void ft_binit_str(ByteArray *b, char *str);
int ft_binit_vformat(ByteArray *b, const char *fmt, va_list ap);
int ft_binsert(ByteArray *b, size_t index, char c);
int ft_binsert_range(ByteArray *b, size_t index, const void *data, size_t size);
int ft_bpush_back(ByteArray *b, char c);
int ft_bpush_back_range(ByteArray *b, const void *data, size_t size);
int ft_bpush_front(ByteArray *b, char c);
int ft_bpush_front_range(ByteArray *b, const void *data, size_t size);
int ft_breserve(ByteArray *b, size_t newSize);
int ft_bshrink_to_fit(ByteArray *b);

#endif
