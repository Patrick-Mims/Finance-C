#ifndef QUEUE_H
#define QUEUE_H

void *new_node();

int queue_dequeue(queue_t *, void **);
int queue_enqueue(queue_t *, const void *);
int queue_size(const queue_t *);
void *destroy(queue_t *);
void queue_init(queue_t *, void(*destroy)(void *));
void queue_peek(const queue_t *);

#endif