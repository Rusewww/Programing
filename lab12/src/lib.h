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
#include <ctype.h>

#ifndef PROGRAMING_LIB_H
#define PROGRAMING_LIB_H

int inputWithScanfCount(char *pos);

void fillArrayScanf(int *mass, int count);

void printfOutArray(int *arr, int count);

void combine(const int *mass1, const int *mass2, int *res, int n, int m);

void sortArray(int n, int *arr);

int charToInt(char *string, int *numbers);

void intToChar(char *output, const int *numbers, int count_of_numbers);

void useScanfAndPrintf();

void usePutsAndGets();

void useReadAndWrite();

void read(int i, char *mass1, size_t nbytes);

void write(int i, char string[13], size_t i1);

#endif //PROGRAMING_LIB_H
