#include "list.h"

// Defined in main
// Mmust be defined as a global variable (in main) to use locally, 
// must be proceeded with keyword: extern
extern int k;

/**
 * The list_init operation initializes a linked list so that it can
 * be used in other operation. Initializing a linked list is a simple
 * operation in which the size member of the list is set to 0, the
 * destroy member to destroy, and the head and tail pointers to NULL.
 */

 // initialize the list
void list_init(node_t *list, void (*destroy)(void *))
{
    list->symbol = NULL;
    list->trade = NULL;
    list->c = NULL;
    list->i = NULL;
    list->p = NULL;
    list->p = NULL;
    list->s = NULL;
    list->t = NULL;
    list->x = NULL;
    list->z = NULL;
    list->data = NULL;

    return;
}

static int count = 0; 
/**
 * Singly Linked List, usually simply called linked lists, are
 * composted of individual elements, each linked by a single pointer.
 */
void list_ins(node_t **list, char *item)
{
    node_t *node = (node_t *)new_node();

    strncpy(node->symbol, node, sizeof(node->symbol));

    node->next = *list;
    count++;

    *list = node;
}

/**
 * With Singly linked lists, the list can be traversed in only 
 * one direction - from head to tail. 
 * Because each element contains no link to its prdecessor. 
 */

// #define list_size(list_t) ((list)->size);

int list_size(const list_t *list)
{
    printf("k => %d", k);
    return list->size;
}