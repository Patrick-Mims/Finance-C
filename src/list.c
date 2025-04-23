#include "list.h"

void *node_factory()
{
    void *node = NULL;

    if((node = malloc(sizeof(void *)))== NULL) exit(EXIT_FAILURE);

    return node;
}

void insert(node_t **list, char *item)
{
    node_t *node = (node_t *)node_factory();

    strncpy(node->symbol, node, sizeof(node->symbol));

    node->next = *list;

    *list = node;
}
