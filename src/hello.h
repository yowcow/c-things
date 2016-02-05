#ifndef HELLO_H_
#define HELLO_H_

#include <stdlib.h>
#include <stdio.h>

#include "member.h"

char* get_message(char* name) {
    char* message = (char *) malloc(sizeof(char) * 100);
    sprintf(message, "Hello world, %s", name);
    return message;
}

struct member create_member(int id, char* name) {
    struct member mem = { id, name };
    return mem;
}

#endif
