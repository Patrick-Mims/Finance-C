#include "mc.h"
#include "finance.h"
#include "finsftp.h"
#include "finssh.h"

// Function Pointers
static void *(*hc)() = http_curl;
static void (*mc)() = mysql_conn;

/*
    Ticker and beginning balance
    Task is to track these funds daily and update the
    Fidelity Table in the MySQL DB named Retirement.

    use the mysql binding
*/

/**
 * extern storage class enables several src files to share variables. 
 */

int k;

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
    list_t list;
    list_t *li = NULL;

    li = &list;
    li->size = 10;

    // void (*ds)(void *) = list_destroy();
    // list_init(list_t *list, ds);

    puts("Finance 2.0 on the Dev branch 2");
    // mysql_version();

    /* *
     * Set the thread object name.
     */
    pthread_t th01, th02;

    /* *
     * Define threads, using a thread factory.
     */
    thread_factory(&th01, hc);
    // thread_factory(&th02, mc);

    return 0;
}