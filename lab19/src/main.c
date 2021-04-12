#include "list.h"

int main()
{
	int i = 0;
	struct list *watches = newList();
	readFileList(watches, 4);

	printf("\t|=============<Main_menu>=============|\n");
	printf("\t|1 - Show list                        |\n");
	printf("\t|2 - Write list to file               |\n");
	printf("\t|3 - Find with criterion              |\n");
	printf("\t|4 - Sort with criterion              |\n");
	printf("\t|5 - Add link                         |\n");
	printf("\t|6 - Delete link                      |\n");
	printf("\t|7 - Exit                             |\n");
	printf("\t|=====================================|\n");
	printf("\t|Select item... ");
	int item;
	scanf("%d", &item);
	printf("\t|=====================================|\n");

	switch (item) {
	case 1:
		printf("\t|================<List>===============|\n");
		showList(watches);
		printf("\t|=====================================|\n");
		break;
	case 2:
		printf("\t|===========<Write_to_file>===========|\n");
		writeFileList(watches);
		printf("\t|Finally!                             |\n");
		printf("\t|=====================================|\n");
		break;
	case 3:
		printf("\t|=============<Searching>=============|\n");
		printf("\t|w - Waterproof                       |\n");
		printf("\t|p - Price                            |\n");
		printf("\t|f - Firm                             |\n");
		printf("\t|c - Country                          |\n");
		printf("\t|s - Style                            |\n");
		printf("\t|=====================================|\n");
		printf("\t|Select criterion... ");
		char criterion;
		scanf("%c", &criterion);
		findWithCriterion(watches, criterion);
		printf("\t|=====================================|\n");
		break;
	case 4:
		i = 0;
		break;
	case 5:
		i = 1;
		break;
	case 6:
		i = 2;
		break;
	default:
		i = -1;
		break;
	}

	//insertEl(watches, 6, 0,"wow",1000,"someses", "Ukraine", 2);
	//writeFileList(watches);
	//showList(watches);

	//findWithCriterion(watches, 'p');

	//deleteEl(watches, 1);
	//showList(watches);

	while (watches->head) {
		struct watchList *p = watches->head;
		watches->head = p->next;
		free(p);
	}
	free(watches);

	return 0;
}