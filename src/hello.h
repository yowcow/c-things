#ifndef HELLO_H_
#define HELLO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "member.h"

char* get_message(char* name) {
    char* message = (char *) malloc(sizeof(char) * (strlen(name) + 14));
    sprintf(message, "Hello world, %s", name);
    return message;
}

struct member create_member(int id, char* name) {
    member_t mem = { id, name };
    return mem;
}

#endif
