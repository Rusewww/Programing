#include "lib.h"
/**
 * @file main.c
 * @brief Interaction with the user by the mechanism of input and output. (Combine two arrays)
 * @author Zozulia Igor.
 * @date 15-feb-2020
 * @version 1.0
 */

/**
 * @param mass1 - first array;
 * @param mass2 - second array;
 * @param res - result array;
 * @return успішний код повернення з програми (0).
 */

/**
Function main: generate two arrays by interaction with user and send data to combine and sort_array.
*/

int main()
{
	printf("%s\n", "Laboratory 12. Author: Zozulia Igor. Interaction with the user by the mechanism of input and output.");

	/*int count = inputWithScanfCount("first");
	char *mass1 = (char *)malloc((unsigned long)((count * 2)) * sizeof(char));
	printf("Enter first array: \n");
	fread(mass1, (count * 2), 1, stdin);

	int sCount = inputWithScanfCount("second");
	char *mass2 = (char *)malloc((unsigned long)((sCount * 2)) * sizeof(char));
	printf("Enter second array: \n");
	fread(mass2, (sCount * 2), 1, stdin);
	strcat(mass1, mass2);

	int *help = (int *)calloc(((strlen(mass1) / 2)), sizeof(int));

	charToInt(mass1, help);

	sort_array((int)strlen(mass1), help);

	intToChar(mass1, help);

	puts("Result of combination arrays: ");
	puts(mass1);
	free(mass1);
	free(mass2);
	free(help);*/

	usePutsAndGets();

	//useScanfAndPrintf();

	return 0;
}
