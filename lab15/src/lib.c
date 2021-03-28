#include "lib.h"

/**
* @file lib.c
* @brief Realization of function.
* @author Zozulia Igor.
* @date 07-dec-2020
* @version 1.0
*/

/**
 * @param filename - name of file;
 * @param input - structure for read;
 */

/**
function read: read structure from file.
*/

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

/**
 * @param filename - name of file;
 * @param output - structure for write;
*/

/**
function write: write structure on file.
*/

void writeToFile(char *filename, struct watch **output, int count)
{
	FILE *outfile;
	outfile = fopen(filename, "wb");
	if (outfile == NULL) {
		printf("%s\n", "Error opening output file.");
		exit(1);
	}
	for (int i = 0; i < count; i++) {
		struct watch *temp = *(output + i);
		fprintf(outfile, "%hd %s %d %s %s %u\n", (temp->waterproof), (temp->model), (temp->cost), (temp->manufacturer.firm),
			(temp->manufacturer.country), (temp->style));
		/*if (temp->style == CLASSIC){
			fprintf(outfile, " Classic");
		}else if(temp->style == SPORT){
			fprintf(outfile, " Sport");
		}else{
			fprintf(outfile, " Fashion");
		}*/
	}
	fclose(outfile);
}

/**
 * @param out - structure for show in console;
*/

/**
function showinconsole: show structure in console.
*/

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

void sortByCriterion(struct watch **fSort, int count, char criterion[10])
{
	char cost[10] = "cost";
	int needSort;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (strcmp(criterion, cost) == 0) {
				if ((*(fSort + j))->cost > (*(fSort + j + 1))->cost) {
					needSort = 1;
				}
			}
			if (needSort == 1) {
				struct watch *temp = *(fSort + j);
				*(fSort + j) = *(fSort + j + 1);
				*(fSort + j + 1) = temp;
				needSort = 0;
			}
		}
	}
}