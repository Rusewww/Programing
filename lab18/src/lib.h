/**
* @file lib.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 28-march-2020
* @version 1.0
*/


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

/**
 * function readFromFile - read data from file;
 * @param filename - name of input file;
 * @param input - name of input struct
 * @param count - count of structures;
 */

void readFromFile(char *filename, struct watch **input, int count);

/**
 * function insert - insert string one to string two;
 * @param text - first string;
 * @param pasted_text - passed string;
 * @param pos - position for passing;
 * @return resulting string;
 */

char *insert(char *text, char *pasted_text, unsigned long pos);

/**
 * function reduce - delete text from string;
 * @param text - string;
 * @param begin - first position for deleting;
 * @param end - second position for deleting;
 * @return result string;
 */

char *reduce(char *text, unsigned int begin, unsigned int end);

/**
 * function insertStruct - insert struct to array;
 * @param watches - struct of watches;
 * @param count - count of watches;
 * @param insert - insert structure;
 * @param position - position for insertion;
 * @return result struct;
 */

struct watch **insertStruct(struct watch **watches, int count, struct watch *insert, int position);

/**
 * function reduceStruct - delete struct from the array;
 * @param watches - struct of watches;
 * @param position - position for insertion;
 * @param count - count of structures;
 * @return result struct;
 */

struct watch **reduceStruct(struct watch **watches, unsigned long position, unsigned long count);

/**
 * function showInConsole - show structure array in console;
 * @param out - array for showing;
 * @param count - count of structures;
 */

void showInConsole(struct watch **out, int count);

#endif