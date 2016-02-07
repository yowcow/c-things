#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hello.h"

int test_get_message() {

    char* result = get_message("Hoge");

    assert(strcmp(result, "Hello world, Hoge") == 0);

    free(result);

    return 1;
}

int test_create_member() {

    member_t* m = create_member(1234, "hoge");

    assert(m->id == 1234);
    assert(strcmp(m->name, "hoge") == 0);

    free(m);

    return 2;
}

int main() {
    int count;
    count = 0;

    count += test_get_message();
    count += test_create_member();

    printf("-- done-testing: %d things\n", count);

    return 0;
}
