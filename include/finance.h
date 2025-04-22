#ifndef FINANCE_H
#define FINANCE_H

#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
};

struct LIBCURL
{
    CURL *curl;
    CURLM *m;
    CURLMSG *msg;
    CURLcode *code;
};

struct NODE
{
    char *symbol;
    char *trade;
    char *c;
    char *i;
    char *p;
    char *s;
    char *t;
    char *x;
    char *z;

    struct NODE *next;
};

void *latest_trade();

#endif