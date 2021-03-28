#include "lib.h"

/**
 * @file main.c
 * @brief Interaction with the user by the mechanism of input and output from file.
 * @author Zozulia Igor.
 * @date 07-dec-2020
 * @version 1.0
 */

/**
 * @param infilename - input file name;
 * @param first - first structure;
 * @param outfilename - output file name;
 * @return успішний код повернення з програми (0).
 */

/**
Function main: generate structure and call function read, showinconsole,.
*/

int main()
{
	printf("%s\n", "Laboratory 15. Author: Zozulia Igor. Interaction with the user by the mechanism of input and output from file.");
	int count = 4;
	struct watch **watchs = malloc((unsigned long)count * sizeof(struct watch));
	for (int i = 0; i < count; i++) {
		*(watchs + i) = malloc(sizeof(struct watch));
	}

	readFromFile("./assets/input.txt", watchs, count);

	//by cost
	/*for (int j = 1; j < count; j++) {
		for (int i = 0; i < count - 1; i++) {
			if ((*(watchs + i))->cost > (*(watchs + i + 1))->cost) {
				struct watch *temp = *(watchs + i);
				*(watchs + i) = *(watchs + i + 1);
				*(watchs + i + 1) = temp;
			}
		}
	}*/

	//by waterproof
	/*for (int j = 1; j < count; j++) {
		for (int i = 0; i < count - 1; i++) {
			if ((*(watchs + i))->waterproof < (*(watchs + i + 1))->waterproof) {
				struct watch *temp = *(watchs + i);
				*(watchs + i) = *(watchs + i + 1);
				*(watchs + i + 1) = temp;
			}
		}
	}*/

	//by style alphabet
	/*for (int j = 1; j < count; j++) {
		for (int i = 0; i < count - 1; i++) {
			if ((*(watchs + i))->style > (*(watchs + i + 1))->style) {
				struct watch *temp = *(watchs + i);
				*(watchs + i) = *(watchs + i + 1);
				*(watchs + i + 1) = temp;
			}
		}
	}*/

	/*for (int j = 1; j < count; j++) {
		for (int i = 0; i < count - 1; i++) {
			if (strcmp((*(watchs + i))->manufacturer.firm,(*(watchs + i + 1))->manufacturer.firm) > 0){
				struct watch *temp = *(watchs + i);
				*(watchs + i) = *(watchs + i + 1);
				*(watchs + i + 1) = temp;
			}
		}
	}*/

	sortByCriterion(watchs,count,"cost");

	showInConsole(watchs, count);

	writeToFile("./dist/output.txt", watchs, count);

	for (int i = 0; i < count; i++) {
		free(*(watchs + i));
	}
	return 0;
}
