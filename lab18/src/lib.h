#ifndef LAB18_LIB_H
#define LAB18_LIB_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Кількість структур у масиві
 */
#define COUNT 6
/**
 *@param SIZE - maximum count of words;
*/

#define SIZE 99
/**
 * Перелік призначень
 */
/*enum Purpose{
	URBAN,
	TACTICAL,
	TOURIST
};

**
 * Структура «Рюкзак»
 *
struct Backpack{
	int laptop_department; // 1 - yes; 0 - no.
	char color[10];
	int volume;
	char country[15];
	enum Purpose enumPurpose;
};*/

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

#endif