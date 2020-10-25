targets = main1.bin main2.bin main3.bin main4.bin main5.bin main6.bin 
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main1.bin main2.bin main3.bin main4.bin main5.bin main6.bin

main1.bin: Program1/src/main1.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main2.bin: Program2/src/main2.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main3.bin: Program3/src/main3.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main4.bin: Program4/src/main4.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main5.bin: Program5/src/main5.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main6.bin: Program6/src/main6.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run1: clean prep compile
	./dist/main1.bin ./dist/main2.bin ./dist/main3.bin ./dist/main4.bin ./dist/main5.bin ./dist/main6.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

