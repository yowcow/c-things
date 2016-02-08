#ifndef HELLO_H_
#define HELLO_H_

typedef struct member {
    int   id;
    char* name;
} member_t;

char* get_message(char* name);

member_t* create_member(int id, char* name);

#endif
