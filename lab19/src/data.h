//
// Created by Rusewww on 4/10/21.
//

#ifndef PROGRAMING_DATA_H
#define PROGRAMING_DATA_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 99

enum watchStyle { ARMOURED, CLASSIC, SPORT };

struct manufacturerStruct {
	char firm[SIZE];
	char country[SIZE];
};

struct watch {
	short waterproof;
	char model[SIZE];
	int cost;
	struct manufacturerStruct manufacturer;
	enum watchStyle style;
};

void menuPrint();

void searchPrint();

#endif //PROGRAMING_DATA_H
