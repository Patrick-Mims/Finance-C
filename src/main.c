#include "finance.h"

int main()
{
    void *(*lt)() = latest_trade; // 

    puts("Finance 2.0 on the Dev branch 2");

    pthread_t th_trade;

    thread_factory(&th_trade, lt);

    return 0;
}