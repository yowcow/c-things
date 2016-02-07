#include <stdio.h>
#include "hello.h"

char* get_message(char* name) {
    char* message = (char*) malloc(sizeof(char) * (strlen(name) + 14));
    sprintf(message, "Hello world, %s", name);
    return message;
}

member_t* create_member(int id, char* name) {
    member_t* mem_ptr = (member_t*) malloc(sizeof(member_t));
    mem_ptr->id = id;
    mem_ptr->name = name;
    return mem_ptr;
}
