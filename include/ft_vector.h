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

void *vector_at(const Vector *vec, size_t index);
int vector_auto_expand(Vector *vec);
size_t vector_capacity(const Vector *vec);
void vector_clear(Vector *vec);
void vector_destroy(Vector *vec);
void vector_dup(Vector *dst, const Vector *src);
void vector_erase(Vector *vec, size_t index);
void vector_erase_range(Vector *vec, size_t start, size_t end);
size_t vector_index(const Vector *vec, const void *key, int (*itemComp)(const void *, const void *));
void vector_init(Vector *vec, size_t itemSize);
void vector_init_buffer(Vector *vec, size_t itemSize, size_t itemCount, void *initialData);
int vector_init_cbuffer(Vector *vec, size_t itemSize, size_t itemCount, const void *initialData);
int vector_init_fill(Vector *vec, size_t itemSize, size_t itemCount, void (*itemCtor)(void *));
int vector_insert(Vector *vec, size_t index, const void *item);
int vector_insert_range(Vector *vec, size_t index, const void *items, size_t itemCount);
void vector_pop_back(Vector *vec);
void vector_pop_front(Vector *vec);
int vector_push_back(Vector *vec, const void *item);
int vector_push_front(Vector *vec, const void *item);
int vector_resize(Vector *vec, size_t newSize);
int vector_reserve(Vector *vec, size_t newCapacity);
void *vector_search(const Vector *vec, const void *key, int (*itemComp)(const void *, const void *));
void vector_set_item_ctor(Vector *vec, void (*itemCtor)(void *));
void vector_set_item_dtor(Vector *vec, void (*itemDtor)(void *));
int vector_shrink_to_fit(Vector *vec);
size_t vector_size(const Vector *vec);
void vector_sort(Vector *vec, int (*itemComp)(const void *, const void *));
void vector_swap(Vector *vec, Vector *other);

#endif
