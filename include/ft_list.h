#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef struct ListNode_
{
    void *data;
    struct ListNode_ *prev;
    struct ListNode_ *next;
}
ListNode;

typedef struct List_
{
    ListNode *front;
    ListNode *back;
    size_t size;
}
List;

void ft_lkdestroy(List *list, void (*dataDtor)(void *));
ptrdiff_t ft_lkdistance(const ListNode *start, const ListNode *end);
List *ft_lkdup(const List *list, void *(*dataDup)(void *), void (*dataDtor)(void *));
int ft_lkemplace(List *list, ListNode *pos, void *data);
int ft_lkemplace_back(List *list, void *data);
int ft_lkemplace_front(List *list, void *data);
void ft_lkerase(List *list, ListNode *node, void (*dataDtor)(void *));
void ft_lkfirst_node(List *list, ListNode *node);
void ft_lkinit(List *list);
void ft_lkinsert(List *list, ListNode *pos, ListNode *newNode);
void ft_lkmerge(List *list, List *other, int (*dataComp)(const void *, const void *));
ListNode *ft_lknode_create(void *data);
void ft_lkpop_back(List *list, void (*dataDtor)(void *));
void ft_lkpop_front(List *list, void (*dataDtor)(void *));
void ft_lkpush_back(List *list, ListNode *newNode);
void ft_lkpush_front(List *list, ListNode *newNode);
size_t ft_lkremove_if(List *list, bool (*dataRemovePred)(const void *), void (*dataDtor)(void *));
void ft_lkreverse(List *list);
size_t ft_lksize(const List *list);
void ft_lksort(List *list, int (*dataComp)(const void *, const void *));
void ft_lksplice_all(List *list, ListNode *pos, List *other);
void ft_lksplice_one(List *list, ListNode *pos, List *other, ListNode *node);
void ft_lksplice_range(List *list, ListNode *pos, List *other, ListNode *first, ListNode *last);
void ft_lkswap(List *list, List *other);
size_t ft_lkunique(List *list, bool (*dataBinaryPred)(const void *, const void *), void (*dataDtor)(void *));

#endif
