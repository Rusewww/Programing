CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep generate

clean:
	rm -rf dist
prep:
	mkdir dist

generate:
	$(CC) -c $(C_OPTS) -fPIC -I../libdynamic/dist src/list.c -o dist/list.o
	$(CC) -c $(C_OPTS) -fPIC -I../libdynamic/dist src/data.c -o dist/data.o
	$(CC) -shared dist/list.o dist/data.o -o dist/libdynamic.so
	rm ./dist/*.o
