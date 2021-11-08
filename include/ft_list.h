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

void list_destroy(List *list, void (*dataDtor)(void *));
ptrdiff_t list_distance(const ListNode *start, const ListNode *end);
List *list_dup(const List *list, void *(*dataDup)(void *), void (*dataDtor)(void *));
int list_emplace(List *list, ListNode *pos, void *data);
int list_emplace_back(List *list, void *data);
int list_emplace_front(List *list, void *data);
void list_erase(List *list, ListNode *node, void (*dataDtor)(void *));
void list_first_node(List *list, ListNode *node);
void list_init(List *list);
void list_insert(List *list, ListNode *pos, ListNode *newNode);
void list_merge(List *list, List *other, int (*dataComp)(const void *, const void *));
ListNode *list_node_create(void *data);
void list_pop_back(List *list, void (*dataDtor)(void *));
void list_pop_front(List *list, void (*dataDtor)(void *));
void list_push_back(List *list, ListNode *newNode);
void list_push_front(List *list, ListNode *newNode);
size_t list_remove_if(List *list, bool (*dataRemovePred)(const void *), void (*dataDtor)(void *));
void list_reverse(List *list);
size_t list_size(const List *list);
void list_sort(List *list, int (*dataComp)(const void *, const void *));
void list_splice_all(List *list, ListNode *pos, List *other);
void list_splice_one(List *list, ListNode *pos, List *other, ListNode *node);
void list_splice_range(List *list, ListNode *pos, List *other, ListNode *first, ListNode *last);
void list_swap(List *list, List *other);
size_t list_unique(List *list, bool (*dataBinaryPred)(const void *, const void *), void (*dataDtor)(void *));

#endif
