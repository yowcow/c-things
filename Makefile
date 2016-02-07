BUILD_OS := $(shell uname)

CC=gcc -Wall -fPIC

ifeq ($(BUILD_OS),Linux)
SO=so
SHARED=-shared
endif

ifeq ($(BUILD_OS),Darwin)
SO=dylib
SHARED=-dynamiclib
endif

libhello.$(SO): src/hello.o
	$(CC) $(SHARED) -O3 -DNDEBUG -lpthread -o libhello.$(SO) src/hello.o

src/hello.o: src/hello.c
	$(CC) -c -O3 -DNDEBUG -D_REENTRANT -D_FILE_OFFSET_BITS=64 -o src/hello.o src/hello.c

test: hello-test
	LD_LIBRARY_PATH=. ./hello-test

hello-test: libhello.$(SO) src/hello.o
	$(CC) -I./ -L./ -o hello-test src/hello-test.c -lhello

clean:
	-rm src/hello.o libhello.$(SO) hello-test
