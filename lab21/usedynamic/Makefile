targets = main.bin test.bin
CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference 
all: clean prep compile

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile: main.bin test.bin

main.bin:
	$(CC) $(C_OPTS) -c src/main.c
	$(CC) -I../libdynamic/dist src/main.c -ldynamic -L../libdynamic/dist -o dist/main.bin -Wl,-rpath,../libdynamic/dist

test.bin:
	$(CC) $(C_OPTS) -c test/test.c
	$(CC) -I../libdynamic/dist test/test.c -ldynamic -L../libdynamic/dist -o dist/test.bin -Wl,-rpath,../libdynamic/dist

run: clean prep compile
	./dist/main.bin

