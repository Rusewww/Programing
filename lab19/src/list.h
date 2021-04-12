//
// Created by Rusewww on 4/10/21.
//

#ifndef PROGRAMING_LIST_H
#define PROGRAMING_LIST_H

#include "data.h"

struct watchList {
	int waterproof;
	char model[SIZE];
	int cost;
	struct manufacturerStruct manufacturer;
	enum watchStyle style;
	struct watchList *next;
	struct watchList *prev;
};

struct list {
	struct watchList *head;
	struct watchList *tail;
};

struct list *newList();

struct watchList *newWatchLink(int wp, const char model[SIZE], int cost, const char firm[SIZE], const char country[SIZE], int style);

void readFileList(struct list *list, int count);

void writeFileList(struct list *list);

void showList(struct list *list);

void insertEl(struct list *list, int position, int wp, char model[SIZE], int cost, char firm[SIZE], char country[SIZE], int style);

void deleteEl(struct list *list, int position);

void findWithCriterion(struct list *list, char criterion);

#endif //PROGRAMING_LIST_H
