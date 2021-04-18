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
	$(CC) -I../libstatic/dist src/main.c -lstatic -L../libstatic/dist -o dist/main.bin

test.bin:
	$(CC) -I../libstatic/dist test/test.c -lstatic -L../libstatic/dist -o dist/test.bin

run: clean prep compile
	./dist/main.bin

