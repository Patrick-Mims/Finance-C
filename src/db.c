#include "db.h"

void mysql_version()
{
    printf("mysql version: %s\n", mysql_get_client_info());
    exit(0);
}

// Set up DB and Table. Less than 40 lines
void db()
{
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}