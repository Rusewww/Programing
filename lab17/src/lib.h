#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/**
* @file lib.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 07-dec-2020
* @version 1.0
*/

/**
 *@param SIZE - maximum count of words;
*/

#define SIZE 99

#ifndef PROGRAMING_LIB_H
#define PROGRAMING_LIB_H

enum watchStyle { ARMOURED, CLASSIC, SPORT };

/**
 * watch - information about watch;
*/

struct watch {
	short waterproof;
	char model[SIZE];
	int cost;
	struct manufacturer {
		char firm[SIZE];
		char country[SIZE];
	} manufacturer;
	enum watchStyle style;
};

void readFromFile(char *filename, struct watch **input, int count);

void writeToFile(char *filename, struct watch **output, int count);

void showInConsole(struct watch **out,int count);

void sortWithCriterion(struct watch **fSort, int count, char *criterion);

void findLowPrice(struct watch **out, int count, int maxCost);

void randomWatch(char *output);

#endif //PROGRAMING_LIB_H
