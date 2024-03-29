#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

void ft_bzero(void *b, size_t size);
void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t size);
void *ft_memchr(const void *b, int c, size_t size);
int ft_memcmp(const void *s1, const void *s2, size_t size);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t size);
void *ft_memmem(const void *big, size_t biglen, const void *little, size_t littlelen);
void *ft_memmove(void *dst, const void *src, size_t size);
void *ft_mempcpy(void *restrict dst, const void *restrict src, size_t size);
void *ft_memset(void *b, int c, size_t size);
char *ft_stpcpy(char *dst, const char *src);
char *ft_stpncpy(char *dst, const char *src, size_t size);
char *ft_strcat(char *restrict dst, const char *restrict src);
char *ft_strchr(const char *s, int c);
char *ft_strchrnul(const char *s, int c);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *restrict dst, const char *restrict src);
size_t ft_strcspn(const char *s, const char *reject);
char *ft_strdup(const char *s);
char *ft_strjoin(const char *s1, const char *s2);
size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t size);
size_t ft_strlen(const char *s);
char *ft_strncat(char *restrict dst, const char *restrict src, size_t size);
int ft_strncmp(const char *s1, const char *s2, size_t size);
char *ft_strncpy(char *restrict dst, const char *restrict src, size_t size);
char *ft_strndup(const char *s, size_t size);
size_t ft_strnlen(const char *s, size_t maxlen);
char *ft_strnstr(const char *big, const char *little, size_t size);
char *ft_strrchr(const char *s, int c);
size_t ft_strspn(const char *s, const char *accept);
char *ft_strstr(const char *big, const char *little);
char *ft_strsub(const char *s, size_t start, size_t size);
char *ft_strtok(char *s, const char *delim);
char *ft_strtok_r(char *s, const char *delim, char **oldptr);
void ft_swap(void *restrict left, void *restrict right, size_t size);

#endif
