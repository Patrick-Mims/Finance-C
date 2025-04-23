#ifndef FINANCE_H
#define FINANCE_H

#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
};

struct LIBCURL
{
    CURL *curl;
    CURLM *curlm;
    CURLMSG *msg;
    CURLcode *code;
};

void *g_trade();
void insert_node();

#endif