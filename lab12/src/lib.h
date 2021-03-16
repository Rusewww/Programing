/**
* @file lib.h
* @brief First declaration of function.
* @author Zozulia Igor.
* @date 07-dec-2020
* @version 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROGRAMING_LIB_H
#define PROGRAMING_LIB_H

int inputWithScanfCount(char *pos);

void fillArrayScanf(int *mass, int count);

void printfOutArray(int *arr, int count);

void combine(const int *mass1, const int *mass2, int *res, int n, int m);

void sort_array(int n, int *arr);

void useScanfAndPrintf();

void charToInt(char *mass1, int *help);

void intToChar(char *mass1, const int *help);

void usePutsAndGets();

#endif //PROGRAMING_LIB_H
