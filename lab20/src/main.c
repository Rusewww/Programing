#include "list.h"

int main()
{
	struct list *watches = newList();
	readFileList(watches, 4);
for (int i = 0; i < SIZE; i++) {
    menuPrint();
    printf("\t|Select item: ");
    int item;
    fscanf(stdin, "%d", &item);

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
            int wp;
            scanf("%i", &wp);

            printf("\t|Model: ");
            char model[SIZE];
            scanf("%s", model);

            printf("\t|Price: ");
            int price;
            scanf("%i", &price);

            printf("\t|Firm: ");
            char firm[SIZE];
            scanf("%s", firm);

            printf("\t|Country: ");
            char country[SIZE];
            scanf("%s", country);

            printf("\t|Style (0 - ARMOURED, 1 - CLASSIC, 2 - SPORT): ");
            enum watchStyle style;
            scanf("%u", &style);
            printf("\t|=====================================|\n");
            printf("\t|Enter position: ");
            int position1;
            scanf("%i", &position1);
            insertLink(watches, position1, wp, model, price, firm, country, (int)style);
            printf("\t|=====================================|\n");

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