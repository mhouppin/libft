NAME := libft.so

SOURCES := $(wildcard sources/*.c)
OBJECTS := $(SOURCES:%.c=%.o)
DEPENDS := $(SOURCES:%.c=%.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -shared -fPIC -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -Wall -Wextra -Wvla -Wshadow -Werror -std=gnu11 -O3 -fno-stack-protector -c -MMD -I include -o $@ $<

-include $(DEPENDS)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	+$(MAKE) all

.PHONY: all clean fclean re
