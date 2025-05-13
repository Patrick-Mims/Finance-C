#ifndef STACK_H
#define STACK_H

#include "datastructure.h" // void *new_node()

void *new_node();
int is_empty();
int is_full();
void peek();
void pop();
void push();

#endif