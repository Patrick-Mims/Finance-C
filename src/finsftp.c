#include "finsftp.h"
#include "list.h"

void sftp_init(int argc, char **argv)
{
    login_t *login = (login_t *)malloc(sizeof(login_t));

    if(login->key == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(login);
        exit(EXIT_FAILURE);
    }

    strncpy(login->key, ".ssh/id_rsa.pub", sizeof(login->key));
    strncpy(login->path, "/tmp/test", sizeof(login->path));
    strncpy(login->privkey, ".ssh/id_rsa", sizeof(login->privkey));
    strncpy(login->pword, "12345", sizeof(login->pword));
    strncpy(login->user, "patrick", sizeof(login->user));

    // sin.sin_family = AF_INET;
    // sin.sin_port = htons(22);
    // sin.sin_addr.s_addr = fin->host;
}