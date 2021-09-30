#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

void ft_bzero(void *b, size_t size);
void *ft_memchr(const void *b, int c, size_t size);
int ft_memcmp(const void *s1, const void *s2, size_t size);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t size);
void *ft_memmem(const void *big, size_t biglen, const void *little, size_t littlelen);
void *ft_memmove(void *dst, const void *src, size_t size);
void *ft_memset(void *b, int c, size_t size);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s);
size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t size);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t size);
size_t ft_strnlen(const char *s, size_t maxlen);
char *ft_strnstr(const char *big, const char *little, size_t size);
char *ft_strrchr(const char *s, int c);

#endif
