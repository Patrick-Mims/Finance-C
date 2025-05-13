#ifndef FINSSH_H
#define FINSSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LibSSH
#include "libssh2_setup.h"
#include <arpa/inet.h>
#include <libssh2.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

libssh2_socket_t sock;

LIBSSH2_SESSION *session;

typedef struct
{
    char *key;
    char *path;
    char *privkey;
    char *pword;
    char *user;
} login_t;

#endif