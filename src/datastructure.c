#include "datastructure.h"

void *new_node()
{
    void *node = NULL;

    if ((node = malloc(sizeof(void *))) == NULL) exit(EXIT_FAILURE);

    return node;
}
