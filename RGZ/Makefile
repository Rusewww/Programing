targets = main.bin
CC = clang++
C_OPTS = -std=gnu++11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/list.cpp src/watch.cpp src/menu.cpp src/controller.cpp
CFLAG = -DDEBUG

all: clean prep compile

clean:
	rm -rf dist
prep:
	mkdir dist
format:
	doxygen
compile: main.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
test: clean prep compile
	./dist/test.bin
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

