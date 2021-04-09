#include "lib.h"

/**
 * @file lib.c
 * @brief Файл з описом функцій оголошених в lib.h
 *
 * @author Zozulia Igor.
 * @date 28-march-2021
 * @version 1.0
 */

char *insert(char *text, char *textForInsertion, unsigned long pos)
{
	if (pos < 0) {
		pos = 0;
	}
	if (pos > strlen(text)) {
		pos = strlen(text);
	}
	char *result = malloc((strlen(text) + strlen(textForInsertion)) * sizeof(char));
	memcpy(result, text, pos);
	memcpy(result + pos, textForInsertion, strlen(textForInsertion));
	memcpy(result + pos + strlen(textForInsertion), text + pos, strlen(text) - pos);
	*(result + strlen(textForInsertion) + strlen(text)) = '\0';
	return result;
}

char *reduce(char *text, unsigned int begin, unsigned int end)
{
	if (begin > end || begin > strlen(text)) {
		return "Error";
	}
	char *result = malloc((strlen(text) - (end - begin)) * sizeof(char));
	memcpy(result, text, begin);
	memcpy((result + begin), (text + end + 1), (strlen(text) - end));
	return result;
}

void readFromFile(char *filename, struct watch **input, int count)
{
	FILE *infile;

	infile = fopen(filename, "r");
	if (infile == NULL) {
		printf("%s\n", "Error opening input file.");
		exit(1);
	}

	for (int i = 0; i < count; i++) {
		struct watch *temp = *(input + i);
		fscanf(infile, "%hd %s %d %s %s %u", &(temp->waterproof), (temp->model), &(temp->cost), (temp->manufacturer.firm),
		       (temp->manufacturer.country), &(temp->style));
	}

	fclose(infile);
}

void showInConsole(struct watch **out, int count)
{
	for (int i = 0; i < count; i++) {
		struct watch *temp = *(out + i);
		if (temp->waterproof == 1) {
			printf("Waterproof: have\n");
		} else {
			printf("Waterproof: no\n");
		}
		fprintf(stdout, "Model: %s\nCost: %dUSD\nManufacturer: %s, %s\n", (temp->model), (temp->cost), (temp->manufacturer.firm),
			(temp->manufacturer.country));
		if (temp->style == CLASSIC) {
			fprintf(stdout, "Style: classic\n");
		} else if (temp->style == SPORT) {
			fprintf(stdout, "Style: sport\n");
		} else {
			fprintf(stdout, "Style: armoured\n");
		}
		printf("\n");
	}
}

struct watch **insertStruct(struct watch **watches, int count, struct watch *insert, int position)
{
	struct watch **result = malloc((unsigned long)(count + 1) * sizeof(struct watch));
	for (int i = 0; i < count + 1; i++) {
		*(result + i) = malloc(sizeof(struct watch));
	}
	if (position < 0) {
		position = 0;
	}
	if (position >= count) {
		position = count;
		memcpy(*result, *watches, sizeof(struct watch) * (unsigned long)(position + 1));
		memcpy(*(result + position), insert, sizeof(struct watch));
		memcpy(*(result + position + 1), *(watches + position), sizeof(struct watch) * (unsigned long)(count - position));
	} else {
		memcpy(*result, *watches, sizeof(struct watch) * (unsigned long)(position));
		memcpy(*(result + position), insert, sizeof(struct watch));
		memcpy(*(result + position + 1), *(watches + position), sizeof(struct watch) * (unsigned long)(count - position + 1));
	}

	count++;

	printf("\nResult of insertion:\n");
	showInConsole(result, count + 1);

	return result;
}

struct watch **reduceStruct(struct watch **watches, int count, int position)
{
	struct watch **result = malloc((unsigned long)(count - 1) * sizeof(struct watch));
	for (int i = 0; i < count - 1; i++) {
		*(result + i) = malloc(sizeof(struct watch));
	}
	if (position < 0) {
		position = 0;
	}
	if (position >= count - 1) {
		position = count;
	}
	memcpy(*result, *watches, sizeof(struct watch) * (unsigned long)(position + 1));
	memcpy(*(result + position), *(watches + position + 1), sizeof(struct watch) * (unsigned long)(count - position));

	printf("\nResult of deletion:\n");
	showInConsole(result, count - 1);

	return result;
}