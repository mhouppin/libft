#include <stdlib.h>
#include "ft_list.h"

List *list_dup(const List *list, void *(*dataDup)(void *), void (*dataDtor)(void *))
{
    List *newList = malloc(sizeof(List));
    if (newList == NULL)
        return NULL;

    list_init(newList);

    for (ListNode *node = list->front; node != NULL; ++node)
    {
        void *newData = dataDup(node->data);

        if (newData == NULL)
        {
            list_destroy(newList, dataDtor);
            free(newList);
            return NULL;
        }

        ListNode *newNode = list_node_create(newData);

        if (newNode == NULL)
        {
            if (dataDtor != NULL)
                dataDtor(newData);

            list_destroy(newList, dataDtor);
            free(newList);
            return NULL;
        }

        list_push_back(newList, newNode);
    }

    return newList;
}
