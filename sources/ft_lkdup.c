#include <stdlib.h>
#include "ft_lklist.h"

lklist_t *ft_lkdup(const lklist_t *list, void *(*dataDup)(void *), void (*dataDtor)(void *))
{
    lklist_t *newList = malloc(sizeof(lklist_t));
    if (newList == NULL)
        return NULL;

    ft_lkinit(newList);

    for (lknode_t *node = list->front; node != NULL; ++node)
    {
        void *newData = dataDup(node->data);

        if (newData == NULL)
        {
            ft_lkdestroy(newList, dataDtor);
            free(newList);
            return NULL;
        }

        lknode_t *newNode = ft_lknode_create(newData);

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
