#ifndef HELLO_H_
#define HELLO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct member {
    int id;
    char* name;
} member_t;

char* get_message(char* name);

member_t* create_member(int id, char* name);

#endif
