NAME := libft.a

CPPFLAGS += -Wall -Wextra -Wvla -Wshadow -Werror -std=gnu11
CFLAGS += -O3

SOURCES := $(wildcard sources/*.c)
OBJECTS := $(SOURCES:%.c=%.o)
DEPENDS := $(SOURCES:%.c=%.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -MMD -I include -o $@ $<

-include $(DEPENDS)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	+$(MAKE) all CFLAGS="$(CFLAGS)" CPPFLAGS="$(CPPFLAGS)"

.PHONY: all clean fclean re
