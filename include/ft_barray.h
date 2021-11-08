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

int barray_auto_expand(ByteArray *b);
size_t barray_capacity(const ByteArray *b);
void barray_clear(ByteArray *b);
void barray_destroy(ByteArray *b);
void barray_erase(ByteArray *b, size_t index);
void barray_erase_range(ByteArray *b, size_t start, size_t end);
int barray_fill(ByteArray *b, size_t index, char c, size_t size);
int barray_fill_back(ByteArray *b, char c, size_t size);
int barray_fill_front(ByteArray *b, char c, size_t size);
void barray_init(ByteArray *b);
void barray_init_buffer(ByteArray *b, void *data, size_t size);
int barray_init_cbuffer(ByteArray *b, const void *data, size_t size);
int barray_init_cstr(ByteArray *b, const char *str);
int barray_init_format(ByteArray *b, const char *fmt, ...);
void barray_init_str(ByteArray *b, char *str);
int barray_init_vformat(ByteArray *b, const char *fmt, va_list ap);
int barray_insert(ByteArray *b, size_t index, char c);
int barray_insert_range(ByteArray *b, size_t index, const void *data, size_t size);
int barray_push_back(ByteArray *b, char c);
int barray_push_back_range(ByteArray *b, const void *data, size_t size);
int barray_push_front(ByteArray *b, char c);
int barray_push_front_range(ByteArray *b, const void *data, size_t size);
int barray_reserve(ByteArray *b, size_t newSize);
int barray_shrink_to_fit(ByteArray *b);

#endif
