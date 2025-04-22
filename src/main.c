#include "finance.h"

int main()
{
    void *(*lt)() = latest_trade;

    puts("Finance 2.0 on the Dev branch 2");

    pthread_t thread_one;

    pthread_create(&thread_one, lt);

    return 0;
}