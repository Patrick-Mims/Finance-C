#include "finance.h"

void thread_factory(pthread_t *thread, const void *(*fn)(void *)) 
{
    void *result;

    // if not successful then it equals a failure.
    if (pthread_create(&thread, NULL, fn, NULL) != 0)
        fprintf(stderr, "Error: pthread_create()");

    pthread_join(thread, &result);
    pthread_exit();
}
