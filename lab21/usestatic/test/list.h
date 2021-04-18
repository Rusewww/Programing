//
// Created by Rusewww on 4/10/21.
//

/**
* @file list.h
* @brief Previous declaration of function.
* @author Zozulia Igor.
* @date 10-april-2021
* @version 1.0
*/

#ifndef PROGRAMING_LIST_H
#define PROGRAMING_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @param SIZE - max length of word
 */

#define SIZE 99

/**
 * watchStyle - styles of watch
 */

enum watchStyle { ARMOURED, CLASSIC, SPORT };

/**
 * manufacturerStruct - structure of manufacturer
 */

struct manufacturerStruct {
	char firm[SIZE];
	char country[SIZE];
};

/**
 * watch - structure of watch
 */

struct watch {
	short waterproof;
	char model[SIZE];
	int cost;
	struct manufacturerStruct manufacturer;
	enum watchStyle style;
};

/**
 * menuPrint - show main menu
 */

void menuPrint();

/**
 * menuPrint - show search menu
 */

void searchPrint();

/**
 * watchList - structure watch like link of list
 */

struct watchList {
	int waterproof;
	char model[SIZE];
	int cost;
	struct manufacturerStruct manufacturer;
	enum watchStyle style;
	struct watchList *next;
	struct watchList *prev;
};

/**
 * list - link of list
 */

struct list {
	struct watchList *head;
	struct watchList *tail;
};

/**
 * newList - generate new list
 */

struct list *newList();

/**
 * newWatchLink - generate new link in list of watch
 * @param wp - waterproof
 * @param model - model of watch
 * @param cost - cost of watch
 * @param firm - firm of watch
 * @param country - country of manufacturer
 * @param style - style of watch
 * @return structure watch like link of watch
 */
struct watchList *newWatchLink(int wp, const char model[SIZE], int cost, const char firm[SIZE], const char country[SIZE], int style);

/**
 * readFileList - read list from file
 * @param list - pointer to list
 * @param count - count of link
 */

void readFileList(struct list *list, int count);

/**
 * writeFileList - write list to file
 * @param list - pointer to list
 */

void writeFileList(struct list *list);

/**
 * showList - show list in console
 * @param list - pointer to list
 */

void showList(struct list *list);

/**
 * insertLink - insert link to list
 * @param list - pointer to list
 * @param position - position of insertion
 * @param wp - waterproof
 * @param model - model of watch
 * @param cost - cost of watch
 * @param firm - firm of watch
 * @param country - country of manufacturer
 * @param style - style of watch
 */

void insertLink(struct list *list, int position, int wp, char model[SIZE], int cost, char firm[SIZE], char country[SIZE], int style);

/**
 * deleteLink - delete link from list
 * @param list - pointer to list
 * @param position - position of deletion
 */

void deleteLink(struct list *list, int position);

/**
 * findWithCriterion - find all watch by criterion
 * @param list - pointer to list
 * @param criterion - criterion for searching
 */

void findWithCriterion(struct list *list, int criterion);

/**
 * compare - compare two link
 * @param first - first link
 * @param second - second link
 * @return result of comparing
 */

int compare(struct watchList *first, struct watchList *second);

/**
 * sortByPrice - sort link by price criterion
 * @param list - pointer to list
 * @param compare - compare two link
 */

void sortByPrice(struct list *list, int (*compare)(struct watchList *, struct watchList *));

#endif //PROGRAMING_LIST_H
