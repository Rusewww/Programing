#include "lib.h"

/**
 * @return успішний код повернення з програми (0)
 */
int main()
{
	printf("%s\n", "Laboratory 15. Author: Zozulia Igor. Dynamic arrays.");
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


	for (int i = 0; i < COUNT; i++) {
		free(*(watches + i));
	}

	return 0;
}