#ifndef LAB18_LIB_H
#define LAB18_LIB_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

/**
 *@param SIZE - maximum count of words;
*/

#define SIZE 99

enum watchStyle { ARMOURED, CLASSIC, SPORT };

struct manufacturerStruct {
	char firm[SIZE];
	char country[SIZE];
};

/**
 * watch - information about watch;
*/

struct watch {
	short waterproof;
	char model[SIZE];
	int cost;
	struct manufacturerStruct manufacturer;
	enum watchStyle style;
};

void readFromFile(char *filename, struct watch **input, int count);

char *insert(char *text, char *pasted_text, unsigned long pos);

char *reduce(char *text, unsigned int begin, unsigned int end);

struct watch **insertStruct(struct watch **watches, int count, struct watch *insert, int position);

struct watch **reduceStruct(struct watch **watches, unsigned long position, unsigned long count);

void showInConsole(struct watch **out, int count);

#endif