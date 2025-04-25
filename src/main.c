#include "database.h"
#include "finance.h"
#include "finsftp.h"
#include "finssh.h"

/*
    Ticker and beginning balance
    Task is to track these funds daily and update the 
    Fidelity Table in the MySQL DB named Retirement.

    use the mysql binding
*/

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
    mysql_version();

    void *(*gt)() = g_trade;
    void (*db)() = db;

    pthread_t th_db, th_trade;

    thread_factory(&th_trade, gt);
    // thread_factory(&th_db, db);

    return 0;
}