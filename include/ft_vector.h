#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define VECTOR_MIN_BYTE_ALLOC 64

typedef struct Vector_
{
    char *data;
    size_t itemSize;
    size_t itemCount;
    size_t maxItemCount;
    void (*itemCtor)(void *);
    void (*itemDtor)(void *);
}
Vector;

void *ft_vat(const Vector *vec, size_t index);
int ft_vauto_expand(Vector *vec);
size_t ft_vcapacity(const Vector *vec);
void ft_vclear(Vector *vec);
void ft_vdestroy(Vector *vec);
void ft_vdup(Vector *dst, const Vector *src);
void ft_verase(Vector *vec, size_t index);
void ft_verase_range(Vector *vec, size_t start, size_t end);
void ft_vinit(Vector *vec, size_t itemSize);
void ft_vinit_buffer(Vector *vec, size_t itemSize, size_t itemCount, void *initialData);
int ft_vinit_cbuffer(Vector *vec, size_t itemSize, size_t itemCount, const void *initialData);
int ft_vinit_fill(Vector *vec, size_t itemSize, size_t itemCount, void (*itemCtor)(void *));
int ft_vinsert(Vector *vec, size_t index, const void *item);
int ft_vinsert_range(Vector *vec, size_t index, const void *items, size_t itemCount);
void ft_vpop_back(Vector *vec);
void ft_vpop_front(Vector *vec);
int ft_vpush_back(Vector *vec, const void *item);
int ft_vpush_front(Vector *vec, const void *item);
int ft_vresize(Vector *vec, size_t newSize);
int ft_vreserve(Vector *vec, size_t newCapacity);
void ft_vset_item_ctor(Vector *vec, void (*itemCtor)(void *));
void ft_vset_item_dtor(Vector *vec, void (*itemDtor)(void *));
int ft_vshrink_to_fit(Vector *vec);
size_t ft_vsize(const Vector *vec);
int ft_vsort(Vector *vec, int (*itemComp)(const void *, const void *));
void ft_vswap(Vector *vec, Vector *other);

#endif
