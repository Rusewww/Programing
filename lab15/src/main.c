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

	char *criterion = (char *)calloc(255, sizeof(char));
	printf("Enter criterion for sort: \n");
	scanf("%s", criterion);
	sortByCriterion(watchs,count,criterion);

	int maxCost;
	printf("Enter max cost of watch: \n");
	scanf("%i", &maxCost);
	findLowPrice(watchs,count,maxCost);

	showInConsole(watchs, count);

	randomWatch("./dist/outputRand.txt");

	writeToFile("./dist/output.txt", watchs, count);

	for (int i = 0; i < count; i++) {
		free(*(watchs + i));
	}
	free(watchs);
	return 0;
}
