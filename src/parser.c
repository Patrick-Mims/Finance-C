#include "finance.h"
#include "finsftp.h"
#include "finssh.h"
#include "list.h"
/**
 * JSON-C Library
 * Parse the request.
 * Insert into a LinkedList.
 */
void json_parser()
{
    // declare pointer variables.
    json_object *root, *symbol, *trade, *i, *p, *s, *t, *x, *z;

    // create a list.
    struct NODE *head = (struct NODE *)node();

    // create a stack.
    stack_t stack = stack_new(20);

    // check if file exists.
    if ((root = json_object_from_file("data.json")) == NULL)
        exit(EXIT_FAILURE);

    // print the json 
    printf("The json file \n\n%s\n", json_object_to_json_string(root));

    symbol = json_object_object_get(root, "symbol");
    trade = json_object_object_get(root, "trade");
    i = json_object_object_get(trade, "i");
    p = json_object_object_get(trade, "p");
    s = json_object_object_get(trade, "s");
    t = json_object_object_get(trade, "t");
    x = json_object_object_get(trade, "x");
    z = json_object_object_get(trade, "z");

    printf("symbol -> %s\n", json_object_get_string(symbol));
    printf("trade -> %s\n", json_object_get_string(trade));
    printf("i -> %s\n", json_object_get_string(i));
    printf("p -> %s\n", json_object_get_string(p));
    printf("s -> %s\n", json_object_get_string(s));
    printf("t -> %s\n", json_object_get_string(t));
    printf("x -> %s\n", json_object_get_string(x));
    printf("z -> %s\n", json_object_get_string(z));

    // test with pretty print.
    printf("%s\n", json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY));

    list_insert(&head, json_object_get_string(symbol), json_object_get_string(i), json_object_get_string(p), json_object_get_string(s), json_object_get_string(t), json_object_get_string(x), json_object_get_string(z));
    
    // parse the json response.
    /*
    symbol = json_object_object_get(root, "symbol");
    trade = json_object_object_get(root, "trade");
    i = json_object_object_get(trade, "i");
    p = json_object_object_get(trade, "p");
    s = json_object_object_get(trade, "s");
    t = json_object_object_get(trade, "t");
    x = json_object_object_get(trade, "x");
    z = json_object_object_get(trade, "z");
    */

    // insert item into list and display.
    //list_insert(&head, symbol, i, p, s, t, x, z);
    //list_insert(&head, p);

    // add the 'symbol' to stack
    // stack_push(stack, symbol);

    // display list
    // list_display(head);

    // peek at stack
    // stack_peek(stack);

    // db_create_db();
    // this creates a new table named after the 'symbol' object.
    // db_create_table(head); // pass the list
 
    /* testing purposes only */
    /*
    printf("symbol => %s\n", json_object_get_string(symbol));
    printf("trade => %s\n", json_object_get_string(trade));
    printf("i => %s\n", json_object_get_string(i));
    printf("p => %s\n", json_object_get_string(p));
    printf("s => %s\n", json_object_get_string(s));
    printf("t => %s\n", json_object_get_string(t));
    printf("x => %s\n", json_object_get_string(x));
    printf("z => %s\n", json_object_get_string(z));
    */

    // decrement the reference count of json_object.
    json_object_put(root);

    /**
     * pthread_exit(0) == success
     * Terminate the calling thread, & specify a return value that 
     * can be obtained in another thread by calling pthread_join()
     */

    pthread_exit(0); 
