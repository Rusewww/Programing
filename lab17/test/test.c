#include "lib.h"

bool testSortWaterproof(struct watch **watches, char *error){
	struct watch **expectedWaterproof = malloc(3 * sizeof(struct watch));
	for (int i = 0; i < 3; i++) {
		*(expectedWaterproof + i) = malloc(sizeof(struct watch));
	}

	(*(expectedWaterproof + 0))->waterproof = 1;
	strcpy((*(expectedWaterproof + 0))->model, "CS-55");
	(*(expectedWaterproof + 0))->cost = 300;
	stpcpy((*(expectedWaterproof + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(expectedWaterproof + 0))->manufacturer.country, "Japan");
	(*(expectedWaterproof + 0))->style = ARMOURED;

	(*(expectedWaterproof + 1))->waterproof = 0;
	strcpy((*(expectedWaterproof + 1))->model, "ZEP-154");
	(*(expectedWaterproof + 1))->cost = 900;
	stpcpy((*(expectedWaterproof + 1))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(expectedWaterproof + 1))->manufacturer.country, "Germany");
	(*(expectedWaterproof + 1))->style = CLASSIC;

	(*(expectedWaterproof + 2))->waterproof = 0;
	strcpy((*(expectedWaterproof + 2))->model, "PG-13");
	(*(expectedWaterproof + 2))->cost = 700;
	stpcpy((*(expectedWaterproof + 2))->manufacturer.firm, "PIAGET");
	stpcpy((*(expectedWaterproof + 2))->manufacturer.country, "Switzerland");
	(*(expectedWaterproof + 2))->style = SPORT;

	bool result = true;

	sortWithCriterion(watches, 3, "waterproof");
	for (int i = 0; i < 3; i++) {
		if ((*(watches + i))->waterproof == ((*(expectedWaterproof + i))->waterproof)) {
			result = true;
		} else {
			result = false;
		}
	}
	if(result == false){
		strcat(error,"error occurred with criterion 'waterproof'; \n");
	}

	for (int i = 0; i < 3; i++) {
		free(*(expectedWaterproof + i));
	}
	free(expectedWaterproof);

	return result;
}

bool testSortCost(struct watch **watches, char *error){
	struct watch **expectedCost = malloc(3 * sizeof(struct watch));
	for (int i = 0; i < 3; i++) {
		*(expectedCost + i) = malloc(sizeof(struct watch));
	}

	(*(expectedCost + 0))->waterproof = 1;
	strcpy((*(expectedCost + 0))->model, "CS-55");
	(*(expectedCost + 0))->cost = 300;
	stpcpy((*(expectedCost + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(expectedCost + 0))->manufacturer.country, "Japan");
	(*(expectedCost + 0))->style = ARMOURED;

	(*(expectedCost + 1))->waterproof = 0;
	strcpy((*(expectedCost + 2))->model, "PG-13");
	(*(expectedCost + 1))->cost = 700;
	stpcpy((*(expectedCost + 1))->manufacturer.firm, "PIAGET");
	stpcpy((*(expectedCost + 1))->manufacturer.country, "Switzerland");
	(*(expectedCost + 1))->style = SPORT;

	(*(expectedCost + 2))->waterproof = 0;
	strcpy((*(expectedCost + 1))->model, "ZEP-154");
	(*(expectedCost + 2))->cost = 900;
	stpcpy((*(expectedCost + 2))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(expectedCost + 2))->manufacturer.country, "Germany");
	(*(expectedCost + 2))->style = CLASSIC;

	bool result = true;

	sortWithCriterion(watches, 3, "cost");
	for (int i = 0; i < 3; i++) {
		if ((*(watches + i))->cost == (*(expectedCost + i))->cost) {
			result = true;
		} else {
			result = false;
		}
	}
	if(result == false){
		strcat(error,"error occurred with criterion 'cost'; \n");
	}

	for (int i = 0; i < 3; i++) {
		free(*(expectedCost + i));
	}
	free(expectedCost);
	return result;
}

bool testSortManufacturer(struct watch **watches, char *error){
	struct watch **expectedManufacturer = malloc(3 * sizeof(struct watch));
	for (int i = 0; i < 3; i++) {
		*(expectedManufacturer + i) = malloc(sizeof(struct watch));
	}

	(*(expectedManufacturer + 0))->waterproof = 1;
	strcpy((*(expectedManufacturer + 0))->model, "CS-55");
	(*(expectedManufacturer + 0))->cost = 300;
	stpcpy((*(expectedManufacturer + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(expectedManufacturer + 0))->manufacturer.country, "Japan");
	(*(expectedManufacturer + 0))->style = ARMOURED;

	(*(expectedManufacturer + 1))->waterproof = 0;
	strcpy((*(expectedManufacturer + 1))->model, "PG-13");
	(*(expectedManufacturer + 1))->cost = 700;
	stpcpy((*(expectedManufacturer + 1))->manufacturer.firm, "PIAGET");
	stpcpy((*(expectedManufacturer + 1))->manufacturer.country, "Switzerland");
	(*(expectedManufacturer + 1))->style = SPORT;

	(*(expectedManufacturer + 2))->waterproof = 0;
	strcpy((*(expectedManufacturer + 2))->model, "ZEP-154");
	(*(expectedManufacturer + 2))->cost = 900;
	stpcpy((*(expectedManufacturer + 2))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(expectedManufacturer + 2))->manufacturer.country, "Germany");
	(*(expectedManufacturer + 2))->style = CLASSIC;

	bool result = true;

	sortWithCriterion(watches, 3, "manufacturer");
	for (int i = 0; i < 3; i++) {
		if (strcmp((*(watches + i))->manufacturer.firm, ((*(expectedManufacturer + i))->manufacturer.firm)) == 0) {
			result = true;
		} else {
			result = false;
		}
	}
	if(result == false){
		strcat(error,"error occurred with criterion 'manufacturer'; \n");
	}

	for (int i = 0; i < 3; i++) {
		free(*(expectedManufacturer + i));
	}
	free(expectedManufacturer);
	return result;
}

bool testSortStyle(struct watch **watches, char *error){
	struct watch **expectedStyle = malloc(3 * sizeof(struct watch));
	for (int i = 0; i < 3; i++) {
		*(expectedStyle + i) = malloc(sizeof(struct watch));
	}

	(*(expectedStyle + 0))->waterproof = 1;
	strcpy((*(expectedStyle + 0))->model, "CS-55");
	(*(expectedStyle + 0))->cost = 300;
	stpcpy((*(expectedStyle + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(expectedStyle + 0))->manufacturer.country, "Japan");
	(*(expectedStyle + 0))->style = ARMOURED;

	(*(expectedStyle + 1))->waterproof = 0;
	strcpy((*(expectedStyle + 1))->model, "ZEP-154");
	(*(expectedStyle + 1))->cost = 900;
	stpcpy((*(expectedStyle + 1))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(expectedStyle + 1))->manufacturer.country, "Germany");
	(*(expectedStyle + 1))->style = CLASSIC;

	(*(expectedStyle + 2))->waterproof = 0;
	strcpy((*(expectedStyle + 2))->model, "PG-13");
	(*(expectedStyle + 2))->cost = 700;
	stpcpy((*(expectedStyle + 2))->manufacturer.firm, "PIAGET");
	stpcpy((*(expectedStyle + 2))->manufacturer.country, "Switzerland");
	(*(expectedStyle + 2))->style = SPORT;

	bool result = true;

	sortWithCriterion(watches, 3, "style");
	for (int i = 0; i < 3; i++) {
		if ((*(watches + i))->style == (*(expectedStyle + i))->style) {
			result = true;
		} else {
			result = false;
		}
	}
	if(result == false){
		strcat(error,"error occurred with criterion 'style'; \n");
	}

	for (int i = 0; i < 3; i++) {
		free(*(expectedStyle + i));
	}
	free(expectedStyle);

	return result;
}

int main()
{
	struct watch **watches = malloc(3 * sizeof(struct watch));
	for (int i = 0; i < 3; i++) {
		*(watches + i) = malloc(sizeof(struct watch));
	}

	(*(watches + 0))->waterproof = 1;
	strcpy((*(watches + 0))->model, "CS-55");
	(*(watches + 0))->cost = 300;
	stpcpy((*(watches + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(watches + 0))->manufacturer.country, "Japan");
	(*(watches + 0))->style = ARMOURED;

	(*(watches + 1))->waterproof = 0;
	strcpy((*(watches + 1))->model, "ZEP-154");
	(*(watches + 1))->cost = 900;
	stpcpy((*(watches + 1))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(watches + 1))->manufacturer.country, "Germany");
	(*(watches + 1))->style = CLASSIC;

	(*(watches + 2))->waterproof = 0;
	strcpy((*(watches + 2))->model, "PG-13");
	(*(watches + 2))->cost = 700;
	stpcpy((*(watches + 2))->manufacturer.firm, "PIAGET");
	stpcpy((*(watches + 2))->manufacturer.country, "Switzerland");
	(*(watches + 2))->style = SPORT;

	bool test = true;
	char *error = (char *)malloc((unsigned long)255 * sizeof(char));

	test &= testSortWaterproof(watches, error);
	test &= testSortCost(watches, error);
	test &= testSortManufacturer(watches, error);
	test &= testSortStyle(watches, error);

	if (test) {
		printf("Test finally passed\n");
	} else {
		printf("Some of the tests failed:\n");
		printf("%s", error);
	}

	for (int i = 0; i < 3; i++) {
		free(*(watches + i));
	}

	free(watches);
	free(error);
	return test;
	return 0;
}