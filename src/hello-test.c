#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hello.h"

int main() {

    assert(
        strcmp(
            get_message("Hoge"),
            "Hello world, Hoge"
        ) == 0
    );

    puts("-- done-testing");

    return 0;
}
