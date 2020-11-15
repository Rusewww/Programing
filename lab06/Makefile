targets = main1.bin main2.bin main3.bin main4.bin main5.bin main6.bin 
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main1.bin main2.bin main3.bin main4.bin main5.bin main6.bin

main1.bin: task01/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main2.bin: task02/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main3.bin: task03/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main4.bin: task04/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main5.bin: task05/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main6.bin: task06/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run1: clean prep compile
	./dist/main1.bin ./dist/main2.bin ./dist/main3.bin ./dist/main4.bin ./dist/main5.bin ./dist/main6.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

