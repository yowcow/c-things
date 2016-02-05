libhello.so: src/hello.o
	$(CC) -shared -Wall -O3 -fPIC -DNDEBUG -lpthread -o libhello.so src/hello.o

src/hello.o: src/hello.c
	$(CC) -c      -Wall -O3 -fPIC -DNDEBUG -D_REENTRANT -D_FILE_OFFSET_BITS=64 -o src/hello.o src/hello.c

test: hello-test
	./hello-test

hello-test: src/hello-test.c
	$(CC) -Wall -O3 -o hello-test src/hello-test.c

clean:
	-rm src/hello.o libhello.so hello-test
