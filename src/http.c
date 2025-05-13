#include "finance.h"

/*
 *   ______        _   _       _     _____ _               _      _____
 *   |  _  \      | \ | |     | |   /  __ \ |             | |    |_   _|
 *   | | | |___   |  \| | ___ | |_  | /  \/ |__   ___  ___| | __   | | _ __
 *   | | | / _ \  | . ` |/ _ \| __| | |   | '_ \ / _ \/ __| |/ /   | || '_ \
 *   | |/ / (_) | | |\  | (_) | |_  | \__/\ | | |  __/ (__|   <   _| || | | |
 *   |___/ \___/  \_| \_/\___/ \__|  \____/_| |_|\___|\___|_|\_\  \___/_| |_|
 * */

// Request Url
static char *api_str() // return the api that we're parsing
{
    char *url = NULL;

    if ((url = malloc(50 * sizeof(char))) == NULL)
        exit(EXIT_FAILURE);

    strcpy(url, "https://data.alpaca.markets");
    strcat(url, "/v2");
    strcat(url, "/stocks");
    strcat(url, "/f");
    strcat(url, "/trades");
    strcat(url, "/latest");

    return url;
}

// Function Pointer Definition
static char *(*api)() = api_str;

// Write the response to a file
static size_t write_callback(char *(*dt)(),
                             size_t size,
                             size_t nmemb,
                             void *stream)
{
    struct IO *io = (struct IO *)stream;

    io->stream = fopen(io->json_file, "wc");

    if (!io->stream)
        exit(EXIT_FAILURE);

    puts("write_callback successful!");

    return fwrite(dt, size, nmemb, io->stream);
}

// Function Pointer Definition
static size_t (*wc)(char *, size_t, size_t, void *) = write_callback;

void *http_curl()
{
    struct IO io = {"trade.json", NULL};
    struct LIBCURL *libcurl = NULL;    // < access libcurl library
    struct curl_slist *headers = NULL; // < needed for headers

    libcurl = (struct LIBCURL *)create_node(); // allocate memory directly.

    libcurl->curl = curl_easy_init();

    // libcurl operations
    curl_easy_setopt(libcurl->curl, CURLOPT_URL, api());
    curl_easy_setopt(libcurl->curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEFUNCTION, wc);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEDATA, &io);

    // send key's via headers
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, "APCA-API-KEY-ID: PKS5C8MOUB65EA7ACRMC");
    headers = curl_slist_append(headers, "APCA-API-SECRET-KEY: 8l0D1LbcPmgbltlmkjxhY2ltdeeRPFfk33jtzq2R");

    curl_easy_setopt(libcurl->curl, CURLOPT_HTTPHEADER, headers);

    if (libcurl->curl == NULL)
        exit(EXIT_FAILURE);

    // make the request and
    libcurl->code = curl_easy_perform(libcurl->curl);

    curl_easy_cleanup(libcurl->curl);

    if (CURLE_OK != libcurl->code)
        fprintf(stderr, "curl told us %d\n", libcurl->code);

    curl_global_cleanup();

    pthread_exit(0); // return success and terminate thread
}