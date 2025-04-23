#include "finance.h"
#include "finsftp.h"
#include "finssh.h"

int main()
{
    puts("Finance 2.0 on the Dev branch 2");

    void *(*gt)() = g_trade;

    pthread_t th_trade;

    thread_factory(&th_trade, gt);

    return 0;
}