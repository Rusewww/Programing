targets = main1.bin main2.bin main3.bin main4.bin main5.bin main6.bin main7.bin main8.bin main9.bin main10.bin main11.bin main12.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile: main1.bin main2.bin main3.bin main4.bin main5.bin main6.bin main7.bin main8.bin main9.bin main10.bin main11.bin main12.bin

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
main7.bin: task07/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main8.bin: task08/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main9.bin: task09/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main10.bin: task10/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main11.bin: task11/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main12.bin: task12/src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main1.bin ./dist/main2.bin ./dist/main3.bin ./dist/main4.bin ./dist/main5.bin ./dist/main6.bin ./dist/main7.bin ./dist/main8.bin ./dist/main9.bin ./dist/main10.bin ./dist/main11.bin ./dist/main12.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO
