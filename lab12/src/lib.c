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
 * @param arr - input array;
 * @param count - length of array;
*/

/**
function fillArrayScanf: fill array using scanf.
*/

void fillArrayScanf(int *arr, int count)
{
	printf("Enter %d numbers:\n", count);
	for (int i = 0; i < count; i++) {
		fscanf(stdin, "%d", &arr[i]);
	}
}

/**
 * @param arr - input array;
 * @param count - length of array;
*/

/**
function printfOutArray: display array using printf.
*/

void printfOutArray(int *arr, int count)
{
	printf("%s\n", "Result of combination arrays: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
}

/**
function useScanfAndPrintf: use printf and scanf for interaction with the user.
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
	puts("\n↑____USING_SCANF_AND_PRINTF____↑\n");

	free(mass1);
	free(mass2);
	free(res);
}

/**
 * @param arr - input array;
 * @param help - helpful array;
*/

/**
function charToInt: convert char to int.
*/

int charToInt(char *string, int *numbers)
{
	char *endptr, *ptr = string;
	int count = 0;

	while (*ptr != '\0') {
		if (isdigit(*ptr)) {
			numbers[count++] = (int)strtol(ptr, &endptr, 10);
		} else {
			endptr = ptr + 1;
		}

		ptr = endptr;
	}
	for (int i = 0; i < count; i++) {
		if (numbers[i] == 0) {
			int buf = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = buf;
		}
	}
	return (count);
}

/**
 * @param output - output array;
 * @param numbers - array of numbers;
 * @param count - count of numbers in array;
*/

/**
function intToChar: convert int to char.
*/

void intToChar(char *output, const int *numbers, int count)
{
	for (int i = 0; i < count; i++) {
		char sNumber[25];
		sprintf(sNumber, "%d", *(numbers + i));
		strcat(output, sNumber);
		if (i < count - 1) {
			strcat(output, " ");
		}
	}
}

/**
function usePutsAndGets: use puts and gets for interaction with the user.
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

	strcat(mass1, " ");
	strcat(mass1, mass2);

	int count = charToInt(mass1, help);

	sort_array(count, help);

	char *result = (char *)calloc(255, sizeof(char));

	intToChar(result, help, count);

	puts("Result of combination arrays: ");
	puts(result);
	puts("↑____USING_GETS_AND_PUTS____↑\n");

	free(mass1);
	free(mass2);
	free(result);
	free(help);
}

/**
function useReadAndWrite: use read and write for interaction with the user.
*/

void useReadAndWrite()
{
	size_t bytes = 255 * sizeof(char);
	char *mass1 = (char *)calloc(255, sizeof(char));
	printf("Enter first array: \n");
	read(1, mass1, bytes);

	char *mass2 = (char *)calloc(255, sizeof(char));
	printf("Enter second array: \n");
	read(1, mass2, bytes);

	strcat(mass1, " ");
	strcat(mass1, mass2);

	int *help = (int *)calloc(255, sizeof(int));

	int count = charToInt(mass1, help);

	sort_array(count, help);

	char *output = (char *)calloc(256, sizeof(char));
	intToChar(output, help, count);

	puts("Result of combination arrays: ");
	write(1, output, strlen(output));
	puts("\n↑____USING_READ_AND_WRITE____↑\n");

	free(mass1);
	free(mass2);
	free(output);
	free(help);
}

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
