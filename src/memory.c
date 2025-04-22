#include "finance.h"

// memory allocating functions
void *create_node()
{
    void *node = NULL;

    if ((node = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return node;
};

void insert(struct NODE **linkedlist,
            char *symbol,
            char *trade,
            char *c,
            char *i,
            char *p,
            char *s,
            char *t,
            char *x,
            char *z)
{
    struct NODE *node = (struct NODE *)create_node();

    strncpy(node->symbol, symbol, sizeof(node->symbol));
    strncpy(node->trade, trade, sizeof(node->trade));
    strncpy(node->c, c, sizeof(node->c));
    strncpy(node->i, i, sizeof(node->i));
    strncpy(node->p, p, sizeof(node->p));
    strncpy(node->s, s, sizeof(node->s));
    strncpy(node->t, t, sizeof(node->t));
    strncpy(node->x, x, sizeof(node->x));
    strncpy(node->z, z, sizeof(node->z));

    node->next = *linkedlist;
    *linkedlist = node;
}