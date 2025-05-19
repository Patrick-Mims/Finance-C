#ifndef FINANCE_H
#define FINANCE_H

#include <curl/curl.h>
#include <pthread.h>

#include "datastructure.h"

typedef struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
} io_t;

typedef struct LIBCURL
{
    CURL *curl;
    CURLcode code;
} libcurl_t;

static char *alpaca_api_str();
void *new_node(); // create a new node
void *http_curl();  // get trade()
void insert_node(); // insert into linked list

#endif