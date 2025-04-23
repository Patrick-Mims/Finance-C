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

/*
#define const char *password = "123456789";
#define const char *privateKey = ".ssh/id_rsa";
#define const char *publicKey = ".ssh/id_rsa.pub";
#define const char *username = "patrick";
#define const char *path= "/tmp/test";

struct LOGIN
{
    char *privkey;
    char *pword;
    char *path;
    char *key;
    char *user;
};

typedef struct LOGIN *login_t;
*/

typedef struct
{
    char *key;
    char *path;
    char *privkey;
    char *pword;
    char *user;
} login_t;

//LOGIN login = {"", ...};

#endif