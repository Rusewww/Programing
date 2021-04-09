#include "lib.h"

/**
 * @return успішний код повернення з програми (0)
 */
int main()
{
	printf("%s\n", "Laboratory 18. Author: Zozulia Igor. Dynamic arrays.");
	char *stringOne = malloc(sizeof(char) * SIZE);
	char *stringTwo = malloc(sizeof(char) * SIZE);

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

	char *textForDel = malloc(sizeof(char) * SIZE);
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

	struct watch **watches = malloc((unsigned long)count * sizeof(struct watch));
	for (int i = 0; i < count; i++) {
		*(watches + i) = malloc(sizeof(struct watch));
	}

	readFromFile("./assets/input.txt", watches, count);

	struct watch *insert = malloc(sizeof(struct watch));

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

	insertStruct(watches, count, insert, position);

	printf("Enter position for deletion: \n");
	scanf("%i", &position);

	reduceStruct(watches, count, 2);

	for (int i = 0; i < count; i++) {
		free(*(watches + i));
	}

	return 0;
}