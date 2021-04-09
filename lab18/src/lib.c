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
