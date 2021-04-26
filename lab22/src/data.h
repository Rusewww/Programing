/**
* @file data.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 28-march-2020
* @version 1.0
*/

#ifndef PROGRAMING_DATA_H
#define PROGRAMING_DATA_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>

/**
 * @paran SIZE - max length of words
 */

#define SIZE 99

/**
 * watchStyle - style of watch
 */

enum watchStyle { ARMOURED, CLASSIC, SPORT };

/**
 * @struct manufacturerStruct - struct of manufacturer
 */

struct manufacturerStruct {
	char firm[SIZE];
	char country[SIZE];
};

/**
 * @struct watch - information about watch;
*/

struct watch {
	short waterproof;
	char model[SIZE];
	int cost;
	struct manufacturerStruct manufacturer;
	enum watchStyle style;
};

/**
 * function menuPrint - print main menu
 */

void menuPrint();

/**
 * function searchPrint - print search menu
 */

void searchPrint();

/**
 * function gets - previous declaration of gets
 * @param str - string
 * @return redden string
 */

char *gets(char *str);

#endif //PROGRAMING_DATA_H
