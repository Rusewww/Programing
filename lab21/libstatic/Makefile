CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep generate

clean:
	rm -rf dist
prep:
	mkdir dist

generate:
	$(CC) -c $(C_OPTS) src/list.c -o ./dist/list.o
	ar rcs ./dist/libstatic.a ./dist/list.o
	rm ./dist/*.o

