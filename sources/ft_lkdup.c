#include <stdlib.h>
#include "ft_lklist.h"

List *ft_lkdup(const List *list, void *(*dataDup)(void *), void (*dataDtor)(void *))
{
    List *newList = malloc(sizeof(List));
    if (newList == NULL)
        return NULL;

    ft_lkinit(newList);

    for (ListNode *node = list->front; node != NULL; ++node)
    {
        void *newData = dataDup(node->data);

        if (newData == NULL)
        {
            ft_lkdestroy(newList, dataDtor);
            free(newList);
            return NULL;
        }

        ListNode *newNode = ft_lknode_create(newData);

        if (newNode == NULL)
        {
            if (dataDtor != NULL)
                dataDtor(newData);

            ft_lkdestroy(newList, dataDtor);
            free(newList);
            return NULL;
        }

        ft_lkpush_back(newList, newNode);
    }

    return newList;
}
