#ifndef FT_LKLIST_H
# define FT_LKLIST_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef struct lknode_s
{
    void *data;
    struct lknode_s *prev;
    struct lknode_s *next;
}
lknode_t;

typedef struct lklist_s
{
    lknode_t *front;
    lknode_t *back;
    size_t size;
}
lklist_t;

void ft_lkdestroy(lklist_t *list, void (*dataDtor)(void *));
ptrdiff_t ft_lkdistance(const lknode_t *start, const lknode_t *end);
lklist_t *ft_lkdup(const lklist_t *list, void *(*dataDup)(void *), void (*dataDtor)(void *));
int ft_lkemplace(lklist_t *list, lknode_t *pos, void *data);
int ft_lkemplace_back(lklist_t *list, void *data);
int ft_lkemplace_front(lklist_t *list, void *data);
void ft_lkerase(lklist_t *list, lknode_t *node, void (*dataDtor)(void *));
void ft_lkfirst_node(lklist_t *list, lknode_t *node);
void ft_lkinit(lklist_t *list);
void ft_lkinsert(lklist_t *list, lknode_t *pos, lknode_t *newNode);
void ft_lkmerge(lklist_t *list, lklist_t *other, int (*dataComp)(const void *, const void *));
lknode_t *ft_lknode_create(void *data);
void ft_lkpop_back(lklist_t *list, void (*dataDtor)(void *));
void ft_lkpop_front(lklist_t *list, void (*dataDtor)(void *));
void ft_lkpush_back(lklist_t *list, lknode_t *newNode);
void ft_lkpush_front(lklist_t *list, lknode_t *newNode);
size_t ft_lkremove_if(lklist_t *list, bool (*dataRemovePred)(const void *), void (*dataDtor)(void *));
void ft_lkreverse(lklist_t *list);
size_t ft_lksize(const lklist_t *list);
void ft_lksort(lklist_t *list, int (*dataComp)(const void *, const void *));
void ft_lksplice_all(lklist_t *list, lknode_t *pos, lklist_t *other);
void ft_lksplice_one(lklist_t *list, lknode_t *pos, lklist_t *other, lknode_t *node);
void ft_lksplice_range(lklist_t *list, lknode_t *pos, lklist_t *other, lknode_t *first, lknode_t *last);
void ft_lkswap(lklist_t *list, lklist_t *other);
size_t ft_lkunique(lklist_t *list, bool (*dataBinaryPred)(const void *, const void *), void (*dataDtor)(void *));

#endif
