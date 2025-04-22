#ifndef FINANCE_H 
#define FINANCE_H 

#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

struct LIBCURL
{
    CURL *curl;
    CURLM *m;
    CURLMSG *msg;
    CURLcode *code;
};

void *latest_trade();

#endif