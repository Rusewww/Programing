/**
* @file lib.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 07-dec-2020
* @version 1.0
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#ifndef PROGRAMING_LIB_H
#define PROGRAMING_LIB_H

void showFileStruct(char *directory, int spaceCount);

void showSize();

double findDirectorySize(char *directory);

#endif //PROGRAMING_LIB_H
