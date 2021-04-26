#include "list.h"

/**
 * @file main.c
 * @brief Regular expressions.
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
	struct list *watches = newList();
	readFileList(watches, 4);
	for (int i = 0; i < SIZE; i++) {
		menuPrint();
		printf("\t|Select item: ");
		char item1[2];
		gets(item1);
		int item = atoi(item1);

		switch (item) {
		case 1:
			printf("\t|================<List>===============|\n");
			showList(watches);
			break;
		case 2:
			printf("\t|===========<Write_to_file>===========|\n");
			writeFileList(watches);
			printf("\t|Finally!                             |\n");
			break;
		case 3:
			searchPrint();
			printf("\t|Select criterion: ");
			int criterion;
			scanf("%i", &criterion);
			findWithCriterion(watches, criterion);
			break;
		case 4:
			printf("\t|==============<Sorting>==============|\n");
			sortByPrice(watches, compare);
			printf("\t|Finally!                             |\n");
			break;
		case 5:
			printf("\t|==========<Generating_link>==========|\n");
			printf("\t|Waterproof: ");
			char wp[2];
			gets(wp);

			printf("\t|Model: ");
			char model[SIZE];
			gets(model);

			printf("\t|Price: ");
			char price[SIZE];
			gets(price);

			printf("\t|Firm: ");
			char firm[SIZE];
			gets(firm);

			printf("\t|Country: ");
			char country[SIZE];
			gets(country);

			printf("\t|Style (0 - ARMOURED, 1 - CLASSIC, 2 - SPORT): ");
			char style[2];
			gets(style);

			bool checking = check(wp, model, price, firm, country, style);
			if (checking) {
				printf("\t|=====================================|\n");
				printf("\t|Enter position: ");
				int position1;
				scanf("%i", &position1);
				int IWp = atoi(wp);
				int ICost = atoi(price);
				int IStyle = atoi(style);
				insertLink(watches, position1, IWp, model, ICost, firm, country, IStyle);
			} else {
				printf("\t|=====================================|\n");
				printf("\t|Error:criterion entered incorrectly  |\n");
			}
			break;
		case 6:
			printf("\t|==============<Deleting>=============|\n");
			printf("\t|Enter position: ");
			int position;
			scanf("%i", &position);
			deleteLink(watches, position);
			printf("\t|Finally!                             |\n");
			break;
		case 7:
			printf("\t|===========<Find_two_words>==========|\n");
			findTwoWords(watches);
			printf("\t|Finally!                             |\n");
			break;
		case 8:
			printf("\t|================<Exit>===============|\n");
			while (watches->head) {
				struct watchList *tmp = watches->head;
				watches->head = tmp->next;
				free(tmp);
			}
			free(watches);
			printf("\t|Finally!                             |\n");
			printf("\t|=====================================|\n");
			return 0;
		default:
			printf("\t|Incorrect variant!                   |\n");
			break;
		}
	}
	while (watches->head) {
		struct watchList *tmp = watches->head;
		watches->head = tmp->next;
		free(tmp);
	}
	free(watches);

	return 0;
}
