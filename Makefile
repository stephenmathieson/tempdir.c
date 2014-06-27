
CC ?= gcc
CFLAGS = -std=c99 -Wall -Wextra -Ideps
# prevent "warning: implicit declaration of function ‘putenv’"
CFLAGS += -D_XOPEN_SOURCE
SRC = tempdir.c $(wildcard deps/*/*.c)
OBJS = $(SRC:.c=.o)
VALGRIND ?=

check: test
	$(VALGRIND) ./test

test: test.o $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -rf test test.o $(OBJS)

.PHONY: check clean
