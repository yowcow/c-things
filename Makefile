BUILD_OS := $(shell uname)

DESTDIR=build
SRCDIR=src

CC=gcc -Wall -fPIC

ifeq ($(BUILD_OS),Linux)
SO=so
SHARED=-shared
endif

ifeq ($(BUILD_OS),Darwin)
SO=dylib
SHARED=-dynamiclib
endif

$(DESTDIR)/libhello.$(SO): $(DESTDIR)/hello.o
	$(CC) $(SHARED) -O3 -DNDEBUG -lpthread -o $(DESTDIR)/libhello.$(SO) $(DESTDIR)/hello.o

$(DESTDIR)/hello.o: $(SRCDIR)/hello.c
	mkdir -p $(DESTDIR)
	$(CC) -c -O3 -DNDEBUG -D_REENTRANT -D_FILE_OFFSET_BITS=64 -o $(DESTDIR)/hello.o $(SRCDIR)/hello.c

test: $(DESTDIR)/hello-test
	LD_LIBRARY_PATH=. $(DESTDIR)/hello-test

$(DESTDIR)/hello-test: $(DESTDIR)/libhello.$(SO) $(SRCDIR)/hello.o
	$(CC) -I$(DESTDIR) -L$(DESTDIR) -o $(DESTDIR)/hello-test $(SRCDIR)/hello-test.c -lhello

clean:
	-rm $(DESTDIR)/hello.o $(DESTDIR)/libhello.$(SO) $(DESTDIR)/hello-test
