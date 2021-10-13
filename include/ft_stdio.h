#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdarg.h>
# include <unistd.h>

int ft_asprintf(char **str, const char *fmt, ...);
int ft_dprintf(int fd, const char *restrict fmt, ...);
int ft_dputchar(char c, int fd);
int ft_dputendl(const char *s, int fd);
int ft_dputnbr(int value, int fd);
int ft_dputstr(const char *s, int fd);
int ft_printf(const char *restrict fmt, ...);
int ft_putchar(char c);
int ft_putendl(const char *s);
int ft_putnbr(int value);
int ft_putstr(const char *s);
int ft_snprintf(char *restrict str, size_t size, const char *restrict fmt, ...);
int ft_sprintf(char *restrict str, const char *restrict fmt, ...);
int ft_vasprintf(char **str, const char *fmt, va_list ap);
int ft_vdprintf(int fd, const char *restrict fmt, va_list ap);
int ft_vprintf(const char *restrict fmt, va_list ap);
int ft_vsnprintf(char *restrict str, size_t size, const char *restrict fmt, va_list ap);
int ft_vsprintf(char *restrict str, const char *restrict fmt, va_list ap);

#endif
