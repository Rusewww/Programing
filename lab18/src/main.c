#include "lib.h"

/**
 * @file main.c
 * @brief Dynamic arrays.
 * @author Zozulia Igor.
 * @date 28-march-2020
 * @version 1.0
 */

/**
 * function main - main program function.
 * @return 0 - successful return code
 */

int main()
{
	printf("%s\n", "Laboratory 18. Author: Zozulia Igor. Dynamic arrays.");
	char *stringOne = (char *)malloc(sizeof(char) * SIZE);
	char *stringTwo = (char *)malloc(sizeof(char) * SIZE);

	printf("Enter first string: \n");
	scanf("%s", stringOne);
	printf("Enter second string: \n");
	scanf("%s", stringTwo);
	int position;
	printf("Enter position for insertion: \n");
	scanf("%i", &position);
	char *resultInsert = insert(stringOne, stringTwo, (unsigned long)position);
	printf("Result of insertion: %s\n\n", resultInsert);

	free(resultInsert);
	free(stringOne);
	free(stringTwo);

	char *textForDel = (char *)malloc(sizeof(char) * SIZE);
	unsigned int begin;
	unsigned int end;

	printf("Enter string for deletion: \n");
	scanf("%s", textForDel);
	printf("Enter begin position: \n");
	scanf("%d", &begin);
	printf("Enter end position: \n");
	scanf("%d", &end);
	char *resultDelete = reduce(textForDel, begin, end);
	printf("Result of delete: %s\n\n", resultDelete);

	free(textForDel);

	int count = 3;

	struct watch **watches = (struct watch **)malloc((unsigned long)count * sizeof(struct watch));
	for (int i = 0; i < count; i++) {
		*(watches + i) = (struct watch *)malloc(sizeof(struct watch));
	}

	readFromFile("D:\\Programing\\lab18\\assets\\input.txt", watches, count);

	struct watch *insert = (struct watch *)malloc(sizeof(struct watch));

	printf("Enter structure for insertion:\n");
	printf("Waterproof (1 - have; 0 - does`t) - ");
	scanf("%hd", &insert->waterproof);
	printf("Model - ");
	scanf("%s", insert->model);
	printf("Cost - ");
	scanf("%d", &insert->cost);
	printf("Firm - ");
	scanf("%s", insert->manufacturer.firm);
	printf("Country - ");
	scanf("%s", insert->manufacturer.country);
	printf("Style (0 - Armoured; 1 - Classic; 2 - Sport) - ");
	scanf("%d", &insert->style);

	printf("Enter position for insertion: \n");
	scanf("%i", &position);

	struct watch **resultOfIns = insertStruct(watches, count, insert, position);

	printf("\nResult of insertion:\n");
	showInConsole(resultOfIns, count + 1);

	int positionForRed;

	printf("Enter position for deletion: \n");
	scanf("%i", &positionForRed);

	struct watch **resultOfRed = reduceStruct(watches, (unsigned long)positionForRed, (unsigned long)count);

	printf("\nResult of deletion:\n");
	showInConsole(resultOfRed, count - 1);

	for (int i = 0; i < count - 1; i++) {
		free(*(resultOfRed + i));
	}
	free(resultOfRed);

	for (int i = 0; i < count; i++) {
		free(*(watches + i));
	}
	free(watches);

	for (int i = 0; i < count - 1; i++) {
		free(*(resultOfIns + i));
	}
	free(resultOfIns);
	return 0;
}