#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct node *next;
} node_t;

void *node_factory();
void insert(node_t **, char *);

#endif