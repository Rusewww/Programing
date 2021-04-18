//
// Created by Rusewww on 4/10/21.
//

#include "list.h"

void menuPrint(){
	printf("\t|=============<Main_menu>=============|\n");
	printf("\t|1 - Show list                        |\n");
	printf("\t|2 - Write list to file               |\n");
	printf("\t|3 - Find with criterion              |\n");
	printf("\t|4 - Sort by price                    |\n");
	printf("\t|5 - Add link                         |\n");
	printf("\t|6 - Delete link                      |\n");
	printf("\t|7 - Exit                             |\n");
	printf("\t|=====================================|\n");
}

void searchPrint(){
	printf("\t|=============<Searching>=============|\n");
	printf("\t|1 - Waterproof                       |\n");
	printf("\t|2 - Price                            |\n");
	printf("\t|3 - Firm                             |\n");
	printf("\t|4 - Country                          |\n");
	printf("\t|5 - Style                            |\n");
	printf("\t|=====================================|\n");
}

struct list *newList()
{
	struct list *listOne = malloc(sizeof(struct list));
	listOne->head = NULL;
	listOne->tail = NULL;
	return listOne;
}

struct watchList *newWatchLink(int wp, const char model[SIZE], int cost, const char firm[SIZE], const char country[SIZE], int style)
{
	struct watchList *watch = malloc(sizeof(struct watchList));
	int i = 0;
	watch->waterproof = wp;;
	while (i < SIZE) {
		watch->model[i] = model[i];
		i++;
	}
	watch->cost = cost;
	i = 0;
	while (i < SIZE) {
		watch->manufacturer.firm[i] = firm[i];
		i++;
	}
	i = 0;
	while (i < SIZE) {
		watch->manufacturer.country[i] = country[i];
		i++;
	}
	watch->style = (enum watchStyle)style;
	watch->next = NULL;
	watch->prev = NULL;

	return watch;
}

void readFileList(struct list *list, int count)
{
	FILE *inputFile = fopen("./assets/input.txt", "r");
	if (inputFile == NULL) {
		printf("\t|Error opening input file.            |\n");
		printf("\t|=====================================|\n");
		exit(1);
	}
	for (int i = 0; i < count; i++) {
		int wp;
		char model[SIZE];
		int cost;
		char firm[SIZE];
		char country[SIZE];
		int style;
		fscanf(inputFile, "%d %s %d %s %s %u\n", &wp, model, &cost, firm, country, &style);
		struct watchList *watch = newWatchLink(wp, model, cost, firm, country, style);
		watch->prev = list->tail;
		if (list->tail) {
			list->tail->next = watch;
		} else {
			list->head = watch;
		}
		list->tail = watch;
	}
	fclose(inputFile);
}

void writeFileList(struct list *list)
{
	FILE *outputFile = fopen("./dist/output.txt", "w");
	if (outputFile == NULL) {
		printf("\t|Error opening output file.           |\n");
		printf("\t|=====================================|\n");
		exit(1);
	}
	for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
		fprintf(outputFile, "%d %s %d %s %s %u\n", watch->waterproof, watch->model, watch->cost, watch->manufacturer.firm,
			watch->manufacturer.country, watch->style);
	}
	fclose(outputFile);
}

void showList(struct list *list)
{
	for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
		if (watch->waterproof == 0) {
			printf("\t|Waterproof: No\n");
		} else {
			printf("\t|Waterproof: Have\n");
		}
		printf("\t|Model:%s\n", watch->model);
		printf("\t|Cost: %dUSD\n", watch->cost);
		printf("\t|Firm: %s\n", watch->manufacturer.firm);
		printf("\t|Country: %s\n", watch->manufacturer.country);
		if (watch->style == ARMOURED) {
			printf("\t|Style: Armoured\n");
		} else if (watch->style == CLASSIC) {
			printf("\t|Style: Classic\n");
		} else if (watch->style == SPORT) {
			printf("\t|Style: Sport\n");
		}
		printf("\t|-------------------------------------|\n");
	}
}

void insertLink(struct list *list, int position, int wp, char model[SIZE], int cost, char firm[SIZE], char country[SIZE], int style)
{
	if (position <= 0) {
		struct watchList *watch = newWatchLink(wp, model, cost, firm, country, style);
		watch->next = list->head;
		if (list->head) {
			list->head->prev = watch;
		} else {
			list->tail = watch;
		}
		list->head = watch;
		return;
	}
	struct watchList *tmp = list->head;
	for (int i = position; i > 0; i--) {
		if (!tmp) {
			struct watchList *watch = newWatchLink(wp, model, cost, firm, country, style);
			watch->prev = list->tail;
			if (list->tail) {
				list->tail->next = watch;
			} else {
				list->head = watch;
			}
			list->tail = watch;
			return;
		}
		tmp = tmp->next;
	}
	struct watchList *watch = newWatchLink(wp, model, cost, firm, country, style);
	watch->prev = tmp->prev;
	watch->next = tmp;
	watch->next->prev = watch;
	watch->prev->next = watch;
}

void deleteLink(struct list *list, int position)
{
	if (position < 0) {
		return;
	}
	struct watchList *temp = list->head;
	if (position == 0) {
		if (!list->head) {
			return;
		}
		list->head = list->head->next;
		if (temp->next) {
			temp->next->prev = NULL;
		} else {
			list->tail = NULL;
		}
		free(temp);
		return;
	}
	for (int i = position; i > 0; i--) {
		if (!temp) {
			return;
		}
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	if (temp->next) {
		temp->next->prev = temp->prev;
	} else {
		list->tail = temp->prev;
	}
	free(temp);
}

void findWithCriterion(struct list *list, int criterion)
{
	int results = 0;
	switch (criterion) {
	case 1:
		printf("\t|=========<Result_of_finding>=========|\n");
		for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
			if (watch->waterproof == 1) {
				results++;
				printf("\t|Waterproof: Have\n");
				printf("\t|Model:%s\n", watch->model);
				printf("\t|Cost: %dUSD\n", watch->cost);
				printf("\t|Firm: %s\n", watch->manufacturer.firm);
				printf("\t|Country: %s\n", watch->manufacturer.country);
				if (watch->style == ARMOURED) {
					printf("\t|Style: Armoured\n");
				} else if (watch->style == CLASSIC) {
					printf("\t|Style: Classic\n");
				} else if (watch->style == SPORT) {
					printf("\t|Style: Sport\n");
				}
				printf("\t|-------------------------------------|\n");
			}
		}
		break;
	case 2:
		printf("\t|Enter max price: ");
		int price;
		scanf("%d", &price);
		printf("\t|=========<Result_of_finding>=========|\n");
		for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
			if (watch->cost <= price) {
				results++;
				if (watch->waterproof == 0) {
					printf("\t|Waterproof: No\n");
				} else {
					printf("\t|Waterproof: Have\n");
				}
				printf("\t|Model:%s\n", watch->model);
				printf("\t|Cost: %dUSD\n", watch->cost);
				printf("\t|Firm: %s\n", watch->manufacturer.firm);
				printf("\t|Country: %s\n", watch->manufacturer.country);
				if (watch->style == ARMOURED) {
					printf("\t|Style: Armoured\n");
				} else if (watch->style == CLASSIC) {
					printf("\t|Style: Classic\n");
				} else if (watch->style == SPORT) {
					printf("\t|Style: Sport\n");
				}
				printf("\t|-------------------------------------|\n");
			}
		}
		break;
	case 3:
		printf("\t|Enter name of firm: ");
		char firm[SIZE];
		scanf("%s", firm);
		printf("\t|=========<Result_of_finding>=========|\n");
		for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
			if (strcmp(watch->manufacturer.firm, firm) == 0) {
				results++;
				if (watch->waterproof == 0) {
					printf("\t|Waterproof: No\n");
				} else {
					printf("\t|Waterproof: Have\n");
				}
				printf("\t|Model:%s\n", watch->model);
				printf("\t|Cost: %dUSD\n", watch->cost);
				printf("\t|Firm: %s\n", watch->manufacturer.firm);
				printf("\t|Country: %s\n", watch->manufacturer.country);
				if (watch->style == ARMOURED) {
					printf("\t|Style: Armoured\n");
				} else if (watch->style == CLASSIC) {
					printf("\t|Style: Classic\n");
				} else if (watch->style == SPORT) {
					printf("\t|Style: Sport\n");
				}
				printf("\t|-------------------------------------|\n");
			}
		}
            break;

        case 4:
            printf("\t|Enter the country: ");
            char country[SIZE];
            scanf("%s", country);
            printf("\t|=========<Result_of_finding>=========|\n");
            for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
                if (strcmp(watch->manufacturer.country, country) == 0) {
                    results++;
                    if (watch->waterproof == 0) {
                        printf("\t|Waterproof: No\n");
                    } else {
                        printf("\t|Waterproof: Have\n");
                    }
                    printf("\t|Model:%s\n", watch->model);
                    printf("\t|Cost: %dUSD\n", watch->cost);
                    printf("\t|Firm: %s\n", watch->manufacturer.firm);
                    printf("\t|Country: %s\n", watch->manufacturer.country);
                    if (watch->style == ARMOURED) {
                        printf("\t|Style: Armoured\n");
                    } else if (watch->style == CLASSIC) {
                        printf("\t|Style: Classic\n");
                    } else if (watch->style == SPORT) {
                        printf("\t|Style: Sport\n");
                    }
                    printf("\t|-------------------------------------|\n");
                }
            }
            break;
        case 5:
            printf("\t|Enter the style of watch: ");
            int style;
            scanf("%d", &style);
            printf("\t|=========<Result_of_finding>=========|\n");
            for (struct watchList *watch = list->head; watch != NULL; watch = watch->next) {
                if (watch->style == (enum watchStyle) style) {
                    results++;;
                    if (watch->waterproof == 0) {
                        printf("\t|Waterproof: No\n");
                    } else {
                        printf("\t|Waterproof: Have\n");
                    }
                    printf("\t|Model:%s\n", watch->model);
                    printf("\t|Cost: %dUSD\n", watch->cost);
                    printf("\t|Firm: %s\n", watch->manufacturer.firm);
                    printf("\t|Country: %s\n", watch->manufacturer.country);
                    if (watch->style == ARMOURED) {
                        printf("\t|Style: Armoured\n");
                    } else if (watch->style == CLASSIC) {
                        printf("\t|Style: Classic\n");
                    } else if (watch->style == SPORT) {
                        printf("\t|Style: Sport\n");
                    }
                    printf("\t|-------------------------------------|\n");
                }
            }
            break;
        default:
            printf("\t|Incorrect variant!                   |\n");
            results = -1;
            break;
    }

    if (results == 0) {
        printf("\t|There are no suitable watches!        |\n");
    } else if (results > 0) {
        printf("\t|We are find %d variant(s)             |\n", results);
    }
}

int compare(struct watchList *first, struct watchList *second) {
    if (first->cost == second->cost)
        return 0;
    else if (first->cost > second->cost)
        return 1;
    else
        return -1;
}

void sortByPrice(struct list *list, int(*compare)(struct watchList *, struct watchList *)) {
    struct watchList *set = list->tail;
    while (set != list->head) {
        struct watchList *temp = list->head->next;
        struct watchList *max = list->head;
        while (temp != set->next) {
            if (compare(temp, max) >= 0)
                max = temp;
            temp = temp->next;
        }
        if (set == max) {
            set = max->prev;
            continue;
        } else if (max == list->head && set == list->tail) {
            list->head = set;
            list->tail = max;
            list->head->next = list->tail->next;
            list->tail->prev = list->head->prev;
            list->head->next->prev = list->head;
            list->tail->prev->next = list->tail;
            list->head->prev = NULL;
            list->tail->next = NULL;
        } else if (max == list->head) {
            list->head = set;
            max->prev = list->head->prev;
            list->head->prev = NULL;
            max->prev->next = max;
            struct watchList *t = max->next;
            max->next = list->head->next;
            list->head->next = t;
            max->next->prev = max;
            list->head->next->prev = list->head;
        } else if (set == list->tail) {
            list->tail = max;
            set->next = list->tail->next;
            list->tail->next = NULL;
            set->next->prev = set;
            struct watchList *t = set->prev;
            set->prev = list->tail->prev;
            list->tail->prev = t;
            set->prev->next = set;
            list->tail->prev->next = list->tail;
        } else {
            struct watchList *t = max->next;
            max->next = set->next;
            set->next = t;
            max->next->prev = max;
            set->next->prev = set;
            t = max->prev;
            max->prev = set->prev;
            set->prev = t;
            max->prev->next = max;
            set->prev->next = set;
        }
        set = max->prev;
    }
}
