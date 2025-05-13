#include "datastructure.h"

/* Generic *new_node() method used by:
 * list.h, queue.h, stack.h
 * */

void *new_node()
{
    void *node = NULL;

    if ((node = malloc(sizeof(void *))) == NULL) exit(EXIT_FAILURE);

    return node;
}
