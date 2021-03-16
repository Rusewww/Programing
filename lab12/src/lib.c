#include "lib.h"

/**
* @file lib.c
* @brief Realization of function.
* @author Zozulia Igor.
* @date 07-dec-2020
* @version 1.0
*/

/**
 * @param pos - order of array;
*/

/**
function inputWithScanfCount: input count using scanf.
*/

int inputWithScanfCount(char *pos)
{
	printf("Enter count of %s array: \n", pos);
	int count;
	fscanf(stdin, "%d", &count);
	return (count);
}

/**
 * @param  - ;
*/

/**
function : .
*/
void fillArrayScanf(int *mass, int count)
{
	printf("Enter %d numbers:\n", count);
	for (int i = 0; i < count; i++) {
		fscanf(stdin, "%d", &mass[i]);
	}
}

/**
 * @param  - ;
*/

/**
function printfOutArray: .
*/

void printfOutArray(int *arr, int count)
{
	printf("%s\n", "Result of combination arrays: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
}

/**
 * @param  - ;
*/

/**
function useScanfAndPrintf: .
*/

void useScanfAndPrintf()
{
	int count = inputWithScanfCount("first");
	int *mass1 = (int *)malloc((unsigned long)count * sizeof(int));
	fillArrayScanf(mass1, count);
	int sCount = inputWithScanfCount("second");
	int *mass2 = (int *)malloc((unsigned int)sCount * sizeof(int));
	fillArrayScanf(mass2, sCount);
	int resCount = count + sCount;
	int *res = (int *)malloc((unsigned long)resCount * sizeof(int));
	combine(mass1, mass2, res, count, sCount);
	sort_array(resCount, res);
	printfOutArray(res, resCount);
	free(mass1);
	free(mass2);
	free(res);
}

/**
 * @param  - ;
*/

/**
function : .
*/

void charToInt(char *mass1, int *help)
{
	for (int i = 0; i < strlen(mass1); i++) {
		if (mass1[i] != ' ' && mass1[i] != '\n') {
			help[i / 2] = ((int)mass1[i]) - '0';
		}
	}
}

/**
 * @param  - ;
*/

/**
function : .
*/

void intToChar(char *mass1, const int *help)
{
	for (int i = 0; i < (strlen(mass1) / 2); i++) {
		mass1[i * 2] = (char)(help[i] + 48);
		if ((i % 2) == 0) {
			mass1[i + 1] = ' ';
		}
	}
}

/**
 * @param  - ;
*/

/**
function : .
*/

void usePutsAndGets()
{
	char *mass1 = (char *)calloc(255, sizeof(char));
	char *mass2 = (char *)calloc(255, sizeof(char));
	int *help = (int *)calloc(255, sizeof(int));
	printf("Enter first array: \n");
	fgets(mass1, 255, stdin);

	printf("Enter second array: \n");
	fgets(mass2, 255, stdin);
	strcat(mass1, mass2);

	charToInt(mass1, help);

	sort_array((int)strlen(mass1) / 2, help);

	intToChar(mass1, help);

	puts("Result of combination arrays: ");
	puts(mass1);
	free(mass1);
	free(mass2);
	free(help);
}

/**
 * @param  - ;
*/

/**
function : .
*/

/**
 * @param mass1 - array one;
 * @param mass2 - array two;
 * @param res - result;
 * @param n - size of first;
 * @param m - size of second;
*/

/**
function combine: combine two arrays.
*/

void combine(const int *mass1, const int *mass2, int *res, int n, int m)
{
	int j = 0;
	for (int i = 0; i < (n + m); i++) {
		if (i < n) {
			*(res + i) = mass1[i];
		} else {
			*(res + i) = mass2[j];
			j++;
		}
	}
}

/**
 * @param arr - array one;
 * @param n - size of first;
*/

/**
function sort_array: sort array.
*/

void sort_array(int n, int *arr)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
