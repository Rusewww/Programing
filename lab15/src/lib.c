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
 * @param count - count of structures;
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
 * @param count - count of structures;
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
 * @param count - count of structures;
*/

/**
function showInConsole: show structure in console.
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

/**
 * @param fSort - structure for sort;
 * @param count - count of structures;
 * @param criterion - sort criterion;
*/

/**
function sortByCriterion: sort structures according to criterion.
*/

void sortByCriterion(struct watch **fSort, int count, char *criterion)
{
	int needSort;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (strcmp(criterion, "cost") == 0) {
				if ((*(fSort + j))->cost > (*(fSort + j + 1))->cost) {
					needSort = 1;
				}
			} else if (strcmp(criterion, "waterproof") == 0) {
				if ((*(fSort + j))->waterproof < (*(fSort + j + 1))->waterproof) {
					needSort = 1;
				}
			} else if (strcmp(criterion, "style") == 0) {
				if ((*(fSort + j))->style > (*(fSort + j + 1))->style) {
					needSort = 1;
				}
			} else if (strcmp(criterion, "manufacturer") == 0) {
				if (strcmp((*(fSort + j))->manufacturer.firm, (*(fSort + j + 1))->manufacturer.firm) > 0) {
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

/**
 * @param fCost - structure where need to find lowest cost;
 * @param count - count of structures;
 * @param maxCost - max cost of watch;
*/

/**
function findLowPrice: find and show all watches that under maxCost.
*/

void findLowPrice(struct watch **fCost, int count, int maxCost)
{
	for (int j = 0; j < count - 1; j++) {
		if ((*(fCost + j))->cost <= maxCost) {
			if ((*(fCost + j))->waterproof == 1) {
				printf("Waterproof: have\n");
			} else {
				printf("Waterproof: no\n");
			}
			fprintf(stdout, "Model: %s\nCost: %dUSD\nManufacturer: %s, %s\n", ((*(fCost + j))->model), ((*(fCost + j))->cost),
				((*(fCost + j))->manufacturer.firm), ((*(fCost + j))->manufacturer.country));
			if ((*(fCost + j))->style == CLASSIC) {
				fprintf(stdout, "Style: classic\n");
			} else if ((*(fCost + j))->style == SPORT) {
				fprintf(stdout, "Style: sport\n");
			} else {
				fprintf(stdout, "Style: armoured\n");
			}
			printf("\n");
		}
	}
}

/**
 * @param output - output structure;
*/

/**
function randomWatch: generate one random struct.
*/

void randomWatch(char *output)
{
	FILE *file = fopen(output, "a");
	if (file == NULL) {
		puts("\nError opening file.");
		exit(1);
	}

	char firmS[4][9] = { "CASIO", "ZEPPELIN", "PIAGET", "SEAGULL" };

	char countryS[4][11] = { "Japan", "Germany", "Switzerland", "China" };

	char modelS[4][5] = { "CA-", "ZP-", "PIA-", "SEG-" };

	char *numbers = strdup("0123456789");

	int numb = (int)(random() % 4);

	char *model = (char *)calloc(SIZE, sizeof(char));
	strcat(model, "Model: ");
	strcat(model, modelS[numb]);
	strcat(model, (numbers + (rand() % 10)));

	char *firm = (char *)calloc(SIZE, sizeof(char));
	strcat(firm, "Firm: ");
	strcat(firm, firmS[numb]);

	char *country = (char *)calloc(SIZE, sizeof(char));
	strcat(country, "Country: ");
	strcat(country, countryS[numb]);

	int waterproof = rand() % 2;
	int cost = rand() % (13 * 10 - 13) + 13;
	int style = rand() % 3;

	if (waterproof == 1) {
		fprintf(file, "Waterproof: have\n");
	} else {
		fprintf(file, "Waterproof: no\n");
	}

	fprintf(file, "%s\n%s\n%s\nCost: %dUSD\n", model, firm, country, cost);

	if (style == CLASSIC) {
		fprintf(file, "Style: classic\n");
	} else if (style == SPORT) {
		fprintf(file, "Style: sport\n");
	} else {
		fprintf(file, "Style: armoured\n");
	}

	free(model);
	free(firm);
	free(country);
	free(numbers);
	fclose(file);
}