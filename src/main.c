#include "finance.h"
#include "finsftp.h"
#include "finssh.h"

const char *funds[] = {
    {"fbltx", 1241.28},
    {"fctdx", 365560.63},
    {"fgomx", 53475.74},
    {"fifgx", 8255.25},
    {"fiwgx", 57674.27},
    {"fscjx", 9378.34},
    {"fspwx", 13329},
    {"fsrjx", 3205.11},
    {"fusix", 112775.24},
    {"fzolx", 5520.31},
    {"fzomx", 3359.71}};

int main()
{
    puts("Finance 2.0 on the Dev branch 2");

    void *(*gt)() = g_trade;

    pthread_t th_trade;

    thread_factory(&th_trade, gt);

    return 0;
}