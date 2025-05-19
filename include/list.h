#ifndef LIST_H
#define LIST_H

#include "datastructure.h"

// Linked List
typedef struct node
{
    char *symbol;
    char *trade;
    char *c;
    char *i;
    char *p;
    char *s;
    char *t;
    char *x;
    char *z;
    void *data;
    struct node *next;
} node_t;

typedef struct list
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    node_t *head, *tail;
} list_t;

// struct Node *new_node();
void *new_node();
void list_destroy(list_t *);
void list_init(node_t *, void (*)(void *));
void list_ins(node_t **, char *);
int list_size(const list_t *);

// #define list_size(list) ((list)->size)

#endif