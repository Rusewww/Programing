#include "lib.h"

bool insertTest()
{
	bool result = true;
	char *stringOne = "abracadabra";
	char *stringTwo = "TEXT";
	char *expected = "abTEXTracadabra";
	int position = 2;
	char *resultInsert = insert(stringOne, stringTwo, (unsigned long)position);
	if (strcmp(expected, resultInsert) == 0) {
		result = true;
	} else {
		result = false;
	}
	free(resultInsert);
	return result;
}

bool reduceTest()
{
	bool result = true;
	char *textForDel = "abTEXTracadabra";
	char *expected = "abracadabra";
	unsigned int begin = 2;
	unsigned int end = 5;
	char *resultDelete = reduce(textForDel, begin, end);
	if (strcmp(resultDelete, expected) == 0) {
		result = true;
	} else {
		result = false;
	}
	free(resultDelete);
	return result;
}

bool insertStructureTest()
{
	bool result = true;
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

	struct watch **expect = malloc(4 * sizeof(struct watch));
	for (int i = 0; i < 4; i++) {
		*(expect + i) = malloc(sizeof(struct watch));
	}

	(*(expect + 0))->waterproof = 1;
	strcpy((*(expect + 0))->model, "CS-55");
	(*(expect + 0))->cost = 300;
	stpcpy((*(expect + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(expect + 0))->manufacturer.country, "Japan");
	(*(expect + 0))->style = ARMOURED;

	(*(expect + 1))->waterproof = 0;
	strcpy((*(expect + 1))->model, "ZEP-154");
	(*(expect + 1))->cost = 900;
	stpcpy((*(expect + 1))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(expect + 1))->manufacturer.country, "Germany");
	(*(expect + 1))->style = CLASSIC;

	(*(expect + 2))->waterproof = 0;
	strcpy((*(expect + 2))->model, "PG-13");
	(*(expect + 2))->cost = 700;
	stpcpy((*(expect + 2))->manufacturer.firm, "PIAGET");
	stpcpy((*(expect + 2))->manufacturer.country, "Switzerland");
	(*(expect + 2))->style = ARMOURED;

	(*(expect + 3))->waterproof = 0;
	strcpy((*(expect + 3))->model, "CS123");
	(*(expect + 3))->cost = 900;
	stpcpy((*(expect + 3))->manufacturer.firm, "CAS2");
	stpcpy((*(expect + 3))->manufacturer.country, "JP");
	(*(expect + 3))->style = CLASSIC;

	struct watch *insert = malloc(sizeof(struct watch));

	(*insert).waterproof = 0;
	strcpy((*insert).model, "CS123");
	(*insert).cost = 900;
	stpcpy((*insert).manufacturer.firm, "CAS2");
	stpcpy((*insert).manufacturer.country, "JP");
	(*insert).style = CLASSIC;

	struct watch **resultInsert = insertStruct(watches, 3, insert, 3);

	for (int i = 0; i < 4; ++i) {
		struct watch *temp1 = *(resultInsert + i);
		struct watch *temp2 = *(expect + i);
		if (temp2->waterproof == temp1->waterproof && temp1->cost == temp2->cost && temp1->style == temp2->style &&
		    strcmp(temp1->model, temp2->model) == 0 && strcmp(temp2->manufacturer.firm, temp1->manufacturer.firm) == 0) {
			result &= true;
		} else {
			result &= false;
		}
	}

	for (int i = 0; i < 4; i++) {
		free(*(expect + i));
	}
	for (int i = 0; i < 3; i++) {
		free(*(watches + i));
	}

	return result;
}

bool reduceStructTest()
{
	bool result = true;
	struct watch **watches1 = malloc(3 * sizeof(struct watch));
	for (int i = 0; i < 3; i++) {
		*(watches1 + i) = malloc(sizeof(struct watch));
	}

	(*(watches1 + 0))->waterproof = 1;
	strcpy((*(watches1 + 0))->model, "CS-55");
	(*(watches1 + 0))->cost = 300;
	stpcpy((*(watches1 + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(watches1 + 0))->manufacturer.country, "Japan");
	(*(watches1 + 0))->style = ARMOURED;

	(*(watches1 + 1))->waterproof = 0;
	strcpy((*(watches1 + 1))->model, "ZP1");
	(*(watches1 + 1))->cost = 900;
	stpcpy((*(watches1 + 1))->manufacturer.firm, "ZEPPELIN");
	stpcpy((*(watches1 + 1))->manufacturer.country, "Germany");
	(*(watches1 + 1))->style = CLASSIC;

	(*(watches1 + 2))->waterproof = 0;
	strcpy((*(watches1 + 2))->model, "PG-13");
	(*(watches1 + 2))->cost = 700;
	stpcpy((*(watches1 + 2))->manufacturer.firm, "PIAGET");
	stpcpy((*(watches1 + 2))->manufacturer.country, "Switzerland");
	(*(watches1 + 2))->style = SPORT;

	struct watch **resultW = reduceStruct(watches1, 1, 3);

	struct watch **expect1 = malloc(2 * sizeof(struct watch));
	for (int i = 0; i < 2; i++) {
		*(expect1 + i) = malloc(sizeof(struct watch));
	}

	(*(expect1 + 0))->waterproof = 1;
	strcpy((*(expect1 + 0))->model, "CS-55");
	(*(expect1 + 0))->cost = 300;
	stpcpy((*(expect1 + 0))->manufacturer.firm, "CASIO");
	stpcpy((*(expect1 + 0))->manufacturer.country, "Japan");
	(*(expect1 + 0))->style = ARMOURED;

	(*(expect1 + 1))->waterproof = 0;
	strcpy((*(expect1 + 1))->model, "PG-13");
	(*(expect1 + 1))->cost = 700;
	stpcpy((*(expect1 + 1))->manufacturer.firm, "PIAGET");
	stpcpy((*(expect1 + 1))->manufacturer.country, "Switzerland");
	(*(expect1 + 1))->style = SPORT;

	for (int i = 0; i < 2; ++i) {
		struct watch *tmp1 = *(resultW + i);
		struct watch *tmp2 = *(expect1 + i);
		if (tmp2->waterproof == tmp1->waterproof && tmp1->cost == tmp2->cost && tmp1->style == tmp2->style &&
		    strcmp(tmp2->manufacturer.firm, tmp1->manufacturer.firm) == 0) {
			result &= true;
		} else {
			result &= false;
		}
	}

	for (int i = 0; i < 3; ++i) {
		free(*(watches1 + i));
	}
	for (int i = 0; i < 2; ++i) {
		free(*(resultW + i));
	}

	return result;
}

int main()
{
	bool test = true;
	char *error = (char *)malloc((unsigned long)255 * sizeof(char));
	test = insertTest();
	if (test == false) {
		strcat(error, "error occurred in function insert; \n");
	}
	test = true;

	test = reduceTest();
	if (test == false) {
		strcat(error, "error occurred in function insert; \n");
	}
	test = true;

	test = insertStructureTest();
	if (test == false) {
		strcat(error, "error occurred in function insertStructure; \n");
	}
	test = true;

	test = reduceStructTest();
	if (test == false) {
		strcat(error, "error occurred in function reduceStructure; \n");
	}
	test = true;

	if (strlen(error) != 0) {
		test = false;
	}

	if (test) {
		printf("Test finally passed\n");
	} else {
		printf("Some of the tests failed:\n");
		printf("%s", error);
	}

	free(error);
	return 0;
}