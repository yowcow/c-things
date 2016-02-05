#ifndef HELLO_H_
#define HELLO_H_

#include <stdlib.h>

char* get_message(char*);

char* get_message(char* name) {
    char* message = (char *) malloc(sizeof(char) * 100);
    sprintf(message, "Hello world, %s", name);
    return message;
}

#endif
