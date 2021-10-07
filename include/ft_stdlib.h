#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

int ft_abs(int value);
int ft_atoi(const char *s);
void *ft_calloc(size_t count, size_t size);
const char *ft_citoa(int value);
char *ft_itoa(int value);
void ft_quicksort(void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *));

#endif
