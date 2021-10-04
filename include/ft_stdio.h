#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>

int ft_dputchar(char c, int fd);
int ft_dputendl(const char *s, int fd);
int ft_dputnbr(int value, int fd);
int ft_dputstr(const char *s, int fd);
int ft_putchar(char c);
int ft_putendl(const char *s);
int ft_putnbr(int value);
int ft_putstr(const char *s);

#endif
