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

static char *api_str();
void *http_curl();  // get trade()
void insert_node(); // insert into linked list

#endif