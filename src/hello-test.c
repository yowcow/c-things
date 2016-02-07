#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hello.h"

int test_get_message() {
    assert(
        strcmp(
            get_message("Hoge"),
            "Hello world, Hoge"
        ) == 0
    );

    return 1;
}

int test_create_member() {
    member_t m;
    m = create_member(1234, "hoge");

    assert(m.id == 1234);
    assert(strcmp(m.name, "hoge") == 0);

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
