NAME := libft.a

CPPFLAGS += -Wall -Wextra -Wvla -Wshadow -Werror -std=gnu11
CFLAGS += -O3

SOURCES := \
	sources/barray/barray_auto_expand.c \
	sources/barray/barray_capacity.c \
	sources/barray/barray_clear.c \
	sources/barray/barray_destroy.c \
	sources/barray/barray_erase.c \
	sources/barray/barray_erase_range.c \
	sources/barray/barray_fill_back.c \
	sources/barray/barray_fill.c \
	sources/barray/barray_fill_front.c \
	sources/barray/barray_init_buffer.c \
	sources/barray/barray_init.c \
	sources/barray/barray_init_cbuffer.c \
	sources/barray/barray_init_cstr.c \
	sources/barray/barray_init_format.c \
	sources/barray/barray_init_str.c \
	sources/barray/barray_init_vformat.c \
	sources/barray/barray_insert.c \
	sources/barray/barray_insert_range.c \
	sources/barray/barray_push_back.c \
	sources/barray/barray_push_back_range.c \
	sources/barray/barray_push_front.c \
	sources/barray/barray_push_front_range.c \
	sources/barray/barray_reserve.c \
	sources/barray/barray_shrink_to_fit.c \
	sources/ctype/ft_isalnum.c \
	sources/ctype/ft_isalpha.c \
	sources/ctype/ft_isascii.c \
	sources/ctype/ft_isblank.c \
	sources/ctype/ft_isdigit.c \
	sources/ctype/ft_isgraph.c \
	sources/ctype/ft_isprint.c \
	sources/ctype/ft_ispunct.c \
	sources/ctype/ft_isspace.c \
	sources/ctype/ft_isxdigit.c \
	sources/ctype/ft_tolower.c \
	sources/ctype/ft_toupper.c \
	sources/heap/heap_adjust.c \
	sources/heap/heap_is_ok.c \
	sources/heap/heap_is_ok_until.c \
	sources/heap/heap_make.c \
	sources/heap/heap_pop.c \
	sources/heap/heap_push.c \
	sources/heap/heap_push_internal.c \
	sources/heap/heap_sort.c \
	sources/list/list_destroy.c \
	sources/list/list_distance.c \
	sources/list/list_dup.c \
	sources/list/list_emplace_back.c \
	sources/list/list_emplace.c \
	sources/list/list_emplace_front.c \
	sources/list/list_erase.c \
	sources/list/list_first_node.c \
	sources/list/list_init.c \
	sources/list/list_insert.c \
	sources/list/list_merge.c \
	sources/list/list_node_create.c \
	sources/list/list_pop_back.c \
	sources/list/list_pop_front.c \
	sources/list/list_push_back.c \
	sources/list/list_push_front.c \
	sources/list/list_remove_if.c \
	sources/list/list_reverse.c \
	sources/list/list_size.c \
	sources/list/list_sort.c \
	sources/list/list_splice_all.c \
	sources/list/list_splice_one.c \
	sources/list/list_splice_range.c \
	sources/list/list_swap.c \
	sources/list/list_unique.c \
	sources/math/ft_clampi.c \
	sources/math/ft_clampu.c \
	sources/math/ft_fabs.c \
	sources/math/ft_fabsf.c \
	sources/math/ft_fabsl.c \
	sources/math/ft_fclamp.c \
	sources/math/ft_fclampf.c \
	sources/math/ft_fclampl.c \
	sources/math/ft_fmax.c \
	sources/math/ft_fmaxf.c \
	sources/math/ft_fmaxl.c \
	sources/math/ft_fmin.c \
	sources/math/ft_fminf.c \
	sources/math/ft_fminl.c \
	sources/math/ft_maxi.c \
	sources/math/ft_maxu.c \
	sources/math/ft_mini.c \
	sources/math/ft_minu.c \
	sources/math/ft_sqrt.c \
	sources/math/ft_sqrtf.c \
	sources/math/ft_sqrti.c \
	sources/math/ft_sqrtl.c \
	sources/math/ft_sqrtu.c \
	sources/mp_queue/mp_queue_destroy.c \
	sources/mp_queue/mp_queue_init.c \
	sources/mp_queue/mp_queue_read.c \
	sources/mp_queue/mp_queue_wait_empty.c \
	sources/mp_queue/mp_queue_wait_filled.c \
	sources/mp_queue/mp_queue_write.c \
	sources/prior_queue/pqueue_destroy.c \
	sources/prior_queue/pqueue_empty.c \
	sources/prior_queue/pqueue_init.c \
	sources/prior_queue/pqueue_pop.c \
	sources/prior_queue/pqueue_push.c \
	sources/prior_queue/pqueue_set_item_cmp.c \
	sources/prior_queue/pqueue_set_item_dtor.c \
	sources/prior_queue/pqueue_size.c \
	sources/prior_queue/pqueue_swap.c \
	sources/stdio/ft_asprintf.c \
	sources/stdio/ft_dprintf.c \
	sources/stdio/ft_dputchar.c \
	sources/stdio/ft_dputendl.c \
	sources/stdio/ft_dputnbr.c \
	sources/stdio/ft_dputstr.c \
	sources/stdio/ft_printf.c \
	sources/stdio/ft_putchar.c \
	sources/stdio/ft_putendl.c \
	sources/stdio/ft_putnbr.c \
	sources/stdio/ft_putstr.c \
	sources/stdio/ft_snprintf.c \
	sources/stdio/ft_sprintf.c \
	sources/stdio/ft_vasprintf.c \
	sources/stdio/ft_vdprintf.c \
	sources/stdio/ft_vprintf.c \
	sources/stdio/ft_vsnprintf.c \
	sources/stdio/ft_vsprintf.c \
	sources/stdlib/ft_abs.c \
	sources/stdlib/ft_atoi.c \
	sources/stdlib/ft_bindex.c \
	sources/stdlib/ft_bsearch.c \
	sources/stdlib/ft_calloc.c \
	sources/stdlib/ft_citoa.c \
	sources/stdlib/ft_itoa.c \
	sources/stdlib/ft_lsearch.c \
	sources/stdlib/ft_quicksort.c \
	sources/string/ft_bzero.c \
	sources/string/ft_memccpy.c \
	sources/string/ft_memchr.c \
	sources/string/ft_memcmp.c \
	sources/string/ft_memcpy.c \
	sources/string/ft_memmem.c \
	sources/string/ft_memmove.c \
	sources/string/ft_mempcpy.c \
	sources/string/ft_memset.c \
	sources/string/ft_stpcpy.c \
	sources/string/ft_stpncpy.c \
	sources/string/ft_strcat.c \
	sources/string/ft_strchr.c \
	sources/string/ft_strchrnul.c \
	sources/string/ft_strcmp.c \
	sources/string/ft_strcpy.c \
	sources/string/ft_strcspn.c \
	sources/string/ft_strdup.c \
	sources/string/ft_strjoin.c \
	sources/string/ft_strlcat.c \
	sources/string/ft_strlcpy.c \
	sources/string/ft_strlen.c \
	sources/string/ft_strncat.c \
	sources/string/ft_strncmp.c \
	sources/string/ft_strncpy.c \
	sources/string/ft_strndup.c \
	sources/string/ft_strnlen.c \
	sources/string/ft_strnstr.c \
	sources/string/ft_strrchr.c \
	sources/string/ft_strspn.c \
	sources/string/ft_strstr.c \
	sources/string/ft_strsub.c \
	sources/string/ft_strtok.c \
	sources/string/ft_strtok_r.c \
	sources/string/ft_swap.c \
	sources/vector/vector_at.c \
	sources/vector/vector_auto_expand.c \
	sources/vector/vector_capacity.c \
	sources/vector/vector_clear.c \
	sources/vector/vector_destroy.c \
	sources/vector/vector_erase.c \
	sources/vector/vector_erase_range.c \
	sources/vector/vector_index.c \
	sources/vector/vector_init_buffer.c \
	sources/vector/vector_init.c \
	sources/vector/vector_init_cbuffer.c \
	sources/vector/vector_init_fill.c \
	sources/vector/vector_insert.c \
	sources/vector/vector_insert_range.c \
	sources/vector/vector_push_back.c \
	sources/vector/vector_push_front.c \
	sources/vector/vector_reserve.c \
	sources/vector/vector_resize.c \
	sources/vector/vector_search.c \
	sources/vector/vector_set_item_ctor.c \
	sources/vector/vector_set_item_dtor.c \
	sources/vector/vector_shrink_to_fit.c \
	sources/vector/vector_size.c \
	sources/vector/vector_sort.c

OBJECTS := $(SOURCES:%.c=%.o)
DEPENDS := $(SOURCES:%.c=%.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo " AR $@"
	@ar -rcs $@ $^

%.o: %.c
	@echo " CC $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -MMD -I include -o $@ $<

-include $(DEPENDS)

clean:
	@echo " RM *.o"
	@rm -f $(OBJECTS)
	@echo " RM *.d"
	@rm -f $(DEPENDS)

fclean:
	@$(MAKE) clean
	@echo " RM $(NAME)"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	+@$(MAKE) all CFLAGS="$(CFLAGS)" CPPFLAGS="$(CPPFLAGS)"

.PHONY: all clean fclean re
