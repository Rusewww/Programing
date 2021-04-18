#include "list.h"
#include <time.h>
#include <syslog.h>

#define al_debug(M, ...) fprintf(stdout, "%s %s %s:%d" M "\n",\
               __DATE__,__TIME__, __FILE__, __LINE__, ##__VA_ARGS__)

#define DEBUG

bool insertLinkTest() {
    bool result = true;

#ifdef DEBUG
    clock_t begin = clock();
    al_debug(" %s ", __FUNCTION__);
#endif

    struct list *list = newList();
    insertLink(list,
               10, 1, "123", 200, "321", "jpeg", 1);
    insertLink(list,
               10, 1, "qwe", 1000, "ewq", "peg", 2);
    insertLink(list,
               10, 0, "qwe-123", 500, "321-ewq", "qwe", 0);
    struct list *right = newList();
    struct watchList *one = newWatchLink(1, "123", 200, "321", "jpeg", 1);
    struct watchList *two = newWatchLink(1, "qwe", 1000, "ewq", "peg", 2);
    struct watchList *three = newWatchLink(0, "qwe-123", 500, "321-ewq", "qwe", 0);
    one->
            prev = NULL;
    one->
            next = two;
    two->
            prev = one;
    two->
            next = three;
    three->
            prev = two;
    three->
            next = NULL;
    right->
            head = one;
    right->
            tail = three;
    struct watchList *watch = list->head;
    struct watchList *tmp = right->head;
    for (; watch != NULL && tmp != NULL;
           watch = watch->next, tmp = tmp->next
            ) {
        if (watch->waterproof == tmp->waterproof && tmp->cost == watch->cost &&
            tmp->style == watch->style &&
            strcmp(watch
                           ->model, tmp->model) == 0 &&
            strcmp(tmp
                           ->manufacturer.firm, watch->manufacturer.firm) == 0) {
            result &=
                    true;
        } else {
            result &=
                    false;
        }
    }
#ifdef DEBUG
    clock_t end = clock();
    double time = (double) (end - begin) / CLOCKS_PER_SEC;
    al_debug(" Spend time: %f second(s)\n",time);
#endif
    while (list->head) {
        struct watchList *a = list->head;
        list->
                head = a->next;
        free(a);
    }
    free(list);

    while (right->head) {
        struct watchList *a1 = right->head;
        right->
                head = a1->next;
        free(a1);
    }
    free(right);

    return
            result;
}

bool deleteLinkTest() {
    bool result = true;

#ifdef DEBUG
    clock_t begin = clock();
    al_debug(" %s ", __FUNCTION__);
#endif

    struct list *list = newList();
    insertLink(list, 10, 1, "123", 200, "321", "jpeg", 1);
    insertLink(list, 10, 1, "qwe", 1000, "ewq", "peg", 2);
    insertLink(list, 10, 0, "qwe-123", 500, "321-ewq", "qwe", 0);
    deleteLink(list, 1);
    struct list *right = newList();
    struct watchList *one = newWatchLink(1, "123", 200, "321", "jpeg", 1);
    struct watchList *two = newWatchLink(0, "qwe-123", 500, "321-ewq", "qwe", 0);
    one->prev = NULL;
    one->next = two;
    two->prev = one;
    two->next = NULL;
    right->head = one;
    right->tail = two;
    struct watchList *watch = list->head;
    struct watchList *tmp = right->head;
    for (; watch != NULL && tmp != NULL; watch = watch->next, tmp = tmp->next) {
        if (watch->waterproof == tmp->waterproof && tmp->cost == watch->cost &&
            tmp->style == watch->style && strcmp(watch->model, tmp->model) == 0 &&
            strcmp(tmp->manufacturer.firm, watch->manufacturer.firm) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

#ifdef DEBUG
    clock_t end = clock();
    double time = (double) (end - begin) / CLOCKS_PER_SEC;
    al_debug(" Spend time: %f second(s)\n",time);
#endif

    while (list->head) {
        struct watchList *b = list->head;
        list->head = b->next;
        free(b);
    }
    free(list);

    while (right->head) {
        struct watchList *b1 = right->head;
        right->head = b1->next;
        free(b1);
    }
    free(right);

    return result;
}

bool sortTest() {
    bool result = true;

#ifdef DEBUG
    clock_t begin = clock();
    al_debug(" %s ", __FUNCTION__);
#endif

    struct list *list = newList();
    insertLink(list, 10, 1, "123", 200, "321", "jpeg", 1);
    insertLink(list, 10, 1, "qwe", 1000, "ewq", "peg", 2);
    insertLink(list, 10, 0, "qwe-123", 500, "321-ewq", "qwe", 0);
    sortByPrice(list, compare);
    struct list *right = newList();
    struct watchList *one = newWatchLink(1, "123", 200, "321", "jpeg", 1);
    struct watchList *two = newWatchLink(0, "qwe-123", 500, "321-ewq", "qwe", 0);
    struct watchList *three = newWatchLink(1, "qwe", 1000, "ewq", "peg", 2);
    one->prev = NULL;
    one->next = two;
    two->prev = one;
    two->next = three;
    three->prev = two;
    three->next = NULL;
    right->head = one;
    right->tail = three;
    struct watchList *watch = list->head;
    struct watchList *tmp = right->head;
    for (; watch != NULL && tmp != NULL; watch = watch->next, tmp = tmp->next) {
        if (watch->waterproof == tmp->waterproof && tmp->cost == watch->cost &&
            tmp->style == watch->style && strcmp(watch->model, tmp->model) == 0 &&
            strcmp(tmp->manufacturer.firm, watch->manufacturer.firm) == 0) {
            result &= true;
        } else {
            result &= false;
        }
    }

#ifdef DEBUG
    clock_t end = clock();
    double time = (double) (end - begin) / CLOCKS_PER_SEC;
    al_debug(" Spend time: %f second(s)\n",time);
#endif

    while (list->head) {
        struct watchList *c = list->head;
        list->head = c->next;
        free(c);
    }
    free(list);

    while (right->head) {
        struct watchList *c1 = right->head;
        right->head = c1->next;
        free(c1);
    }
    free(right);

    return result;
}

int main() {
#ifdef DEBUG
    printf("\t\tDEBUG_ENABLED!\t\n");
    clock_t begin = clock();;
#endif
    bool test = true;

    char *error = (char *) malloc((unsigned long) 255 * sizeof(char));

    test = insertLinkTest();


    if (test == false) {
        strcat(error, "error occurred in function insertLink; \n");
    }
    test = true;
    test = deleteLinkTest();
    if (test == false) {
        strcat(error, "error occurred in function deleteLink; \n");
    }
    test = true;

    test = sortTest();
    if (test == false) {
        strcat(error, "error occurred in function sort; \n");
    }


    if (test) {
#ifdef DEBUG
        al_debug(" Test finally passed\n");
#else
        printf("Test finally passed\n");
#endif
    } else {
#ifdef DEBUG
        al_debug(" Some of the tests failed:\n");
#else
        printf("Some of the tests failed:\n");
#endif
        printf("%s", error);
    }
    free(error);

#ifdef DEBUG
    clock_t end = clock();
    double timeInsLink = (double) (end - begin) / CLOCKS_PER_SEC;
    al_debug(" Spend time: %f second(s)\n", timeInsLink);
#endif
    return 0;
}