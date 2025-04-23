#ifndef FINSFTP_H
#define FINSFTP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include "finssh.h"
#include "libssh2_sftp.h"

struct FINSFTP
{
    char *fingerPrint;
    char *userAuthList;
    int auth_pw;
    int i; 
    int rc;
    uint32_t host;
};

//struct sockaddr_in sin;
LIBSSH2_SFTP *sftp_session;
LIBSSH2_SFTP_HANDLE *sftp_handle;

#endif