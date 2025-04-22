#include "finance.h"

void *latest_trade()
{
    struct IO io = { 
        "trade.json",
        NULL};

    struct LIBCURL *libcurl = NULL; // < access libcurl library 
    struct curl_slist *headers = NULL; // < needed for headers

    libcurl = (struct LIBCURL *)g_memory(); // allocate memory directly.
    libcurl->curl = curl_easy_init();

    curl_easy_setopt(libcurl->curl, CURLOPT_URL, gu());
    curl_easy_setopt(libcurl->curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEFUNCTION, wc);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEDATA, &io);

    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "APCA-API-KEY-ID: PKS5C8MOUB65EA7ACRMC");
    headers = curl_slist_append(headers, "APCA-API-SECRET-KEY: 8l0D1LbcPmgbltlmkjxhY2ltdeeRPFfk33jtzq2R");

    curl_easy_setopt(libcurl->curl, CURLOPT_HTTPHEADER, headers);

    if (libcurl->curl == NULL)
        exit(EXIT_FAILURE);

    libcurl->code = curl_easy_perform(libcurl->curl);

    curl_easy_cleanup(libcurl->curl);

    if (CURLE_OK != libcurl->code)
        fprintf(stderr, "curl told us %d\n", libcurl->code);

    curl_global_cleanup();

    pthread_exit(0); // return success and terminate thread
}
