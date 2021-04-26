/**
 * @file lib.c
 * @brief file of function declared in data.h
 *
 * @author Zozulia Igor.
 * @date 28-march-2021
 * @version 1.0
 */

#include "data.h"

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
