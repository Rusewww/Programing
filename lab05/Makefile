targets = task01.bin task02.bin task03.bin task04.bin task05.bin 
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: task01.bin task02.bin task03.bin task04.bin task05.bin 

task01.bin: task01/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task02.bin: task02/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task03.bin: task03/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task04.bin: task04/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task05.bin: task05/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run1: clean prep compile
	./dist/task01.bin ./dist/task02.bin ./dist/task03.bin ./dist/task04.bin ./dist/task05.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

