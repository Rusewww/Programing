/**
* @file list.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 28-march-2020
* @version 1.0
*/

#ifndef PROGRAMING_LIST_H
#define PROGRAMING_LIST_H

#include "data.h"

/**
 * @struct watchList - link of list with information about watch;
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
 * @struct list - list
 */

struct list {
	struct watchList *head;
	struct watchList *tail;
};

/**
 * function list - generate list
 * @return begin of list
 */

struct list *newList();

/**
 * function newWatchLink - generate list of watch
 * @param wp - waterproof
 * @param model - model of watch
 * @param cost - cost of watch
 * @param firm - firm of watch
 * @param country - country of manufacturer
 * @param style - style of watch
 * @return begin of list
 */

struct watchList *newWatchLink(int wp, const char model[SIZE], int cost, const char firm[SIZE], const char country[SIZE], int style);

/**
 * function readFileList - read list from input file
 * @param list - name of list
 * @param count - count of link
 */

void readFileList(struct list *list, int count);

/**
 * function writeFileList - write list to file
 * @param list - name of list
 */

void writeFileList(struct list *list);

/**
 * function showList - show list in console
 * @param list - name of list
 */

void showList(struct list *list);

/**
 * function insertLink - insert link to list
 * @param list - name of list
 * @param position - position for insertion
 * @param wp - waterproof
 * @param model - model of watch
 * @param cost - cost of watch
 * @param firm - firm of watch
 * @param country - country of manufacturer
 * @param style - style of watch
 */

void
insertLink(struct list *list, int position, int wp, char model[SIZE], int cost, char firm[SIZE], char country[SIZE],
		   int style);

/**
 * function deleteLink - delete link from list
 * @param list - name of list
 * @param position - position for deletion
 */

void deleteLink(struct list *list, int position);

/**
 * function findWithCriterion - find link by criterion
 * @param list - name of list
 * @param criterion - criterion for finding
 */

void findWithCriterion(struct list *list, int criterion);

/**
 * function compare - compare two links
 * @param first - first link
 * @param second - second link
 * @return 0,-1 or 1 - successful return code
 */

int compare(struct watchList *first, struct watchList *second);

/**
 * function sortByPrice - sort list by price
 * @param list - name of list
 * @param compare - compare two links
 */

void sortByPrice(struct list *list, int(*compare)(struct watchList *, struct watchList *));

#endif //PROGRAMING_LIST_H
