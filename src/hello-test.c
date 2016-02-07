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

int test_create_members() {

    int i;
    char* names[3];
    names[0] = "hoge";
    names[1] = "fuga";
    names[2] = "foobar";

    member_t* members[3];

    for (i = 0; i < 3; i++) {
        members[i] = create_member(i + 1, names[i]);
    }

    assert(members[0]->id == 1);
    assert(members[1]->id == 2);
    assert(members[2]->id == 3);

    assert(members[0]->name == "hoge");
    assert(members[1]->name == "fuga");
    assert(members[2]->name == "foobar");

    for (i = sizeof(members) - 1; i >= 0; i--) {
        free(members[i]);
    }

    return 6;
}

int main() {
    int count;
    count = 0;

    count += test_get_message();
    count += test_create_member();
    count += test_create_members();

    printf("-- done-testing: %d things\n", count);

    return 0;
}
