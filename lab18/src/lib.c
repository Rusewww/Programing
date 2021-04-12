#include "lib.h"

/**
 * @file lib.c
 * @brief Файл з описом функцій оголошених в lib.h
 *
 * @author Zozulia Igor.
 * @date 28-march-2021
 * @version 1.0
 */

char *insert(char *text, char *textForInsertion, unsigned long position)
{
	if (position < 0) {
		position = 0;
	}
	if (position > strlen(text)) {
		position = strlen(text);
	}
	char *result = (char *)malloc((strlen(text) + strlen(textForInsertion) + 1) * sizeof(char));
	memcpy(result, text, position);
	memcpy(result + position, textForInsertion, strlen(textForInsertion));
	memcpy(result + position + strlen(textForInsertion), text + position, strlen(text) - position);
	*(result + strlen(textForInsertion) + strlen(text)) = '\0';
	return result;
}

char *reduce(char *text, unsigned int begin, unsigned int end)
{
	if (begin > end || begin > strlen(text)) {
		return "Error";
	}
	char *result = (char *)malloc((strlen(text) - (end - begin)) * sizeof(char));
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
			printf("\tWaterproof: have\n");
		} else {
			printf("\tWaterproof: no\n");
		}
		fprintf(stdout, "\tModel: %s\n\tCost: %dUSD\n\tManufacturer: %s, %s\n", (temp->model), (temp->cost), (temp->manufacturer.firm),
			(temp->manufacturer.country));
		if (temp->style == 1) {
			fprintf(stdout, "\tStyle: classic\n");
		} else if (temp->style == 2) {
			fprintf(stdout, "\tStyle: sport\n");
		} else {
			fprintf(stdout, "\tStyle: armoured\n");
		}
		printf("\n");
	}
}

struct watch **insertStruct(struct watch **watches, int count, struct watch *insert, int position)
{
	struct watch **result = (struct watch **)(char **)malloc((unsigned long)(count + 1) * sizeof(struct watch));
	for (int i = 0; i < count + 1; i++) {
		*(result + i) = (struct watch *)malloc(sizeof(struct watch));
	}
	if (position < 0) {
		position = 0;
	} else if (position >= count){
		position = count;
	}

	memcpy(*result, *watches, sizeof(struct watch) * (unsigned long)position);
	memcpy(*(result + position), insert, sizeof(struct watch));
	memcpy(*(result + position + 1), *(watches + position), (sizeof(struct watch) * (unsigned long)(count - position)));

	return result;
}

struct watch **reduceStruct(struct watch **watches, unsigned long position, unsigned long count)
{
	struct watch **result = (struct watch **)malloc((unsigned long)(count - 1) * sizeof(struct watch));
	for (unsigned long i = 0; i < count -1; i++) {
		*(result + i) = (struct watch *)malloc(sizeof(struct watch));
	}

	if (position < 0) {
		position = 0;
	}

	if (position >= count) {
		position = count - 1;
	}

	memcpy(*result, *watches, (sizeof(struct watch) * position));
	memcpy(*(result + position), *(watches + position + 1), (sizeof(struct watch) * (count - position - 1)));

	return result;
}