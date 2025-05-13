#include "list.h"

void insert(node_t **list, char *item)
{
    node_t *node = (node_t *)new_node();

    strncpy(node->symbol, node, sizeof(node->symbol));

    node->next = *list;

    *list = node;
}


void display(node_t *list)
{}