#include <stdlib.h>
/**
 * @file main.c Завдання 3 лабораторної роботи №6.
 *
 * Перетворити число в рядок.
 */

/**
 * @param num - число для переводу;
 * @param result - результуючий массив;
 * @param RESULTSIZE - розмір результуючого масиву;
 */
static void converting(int num, int RESSIZE, char result[]);
/**
Функція main: задає число, масив результату та його розміри, і передає все до функції converting.
*/
int main(){
        int num = rand() % 10000;
        #define RESULTSIZE 60
        char result[RESULTSIZE];
        converting(num, RESULTSIZE, result);
        return 0;
}
/**
Функція converting: конвертує число в строку.
*/
void converting(int num, int RESSIZE, char result[]){
        #define LENTH 15 //Максимальна довжина одного слова
        #define SIZE 4 //Довжина масиву
        #define COUNT 10
        int b[SIZE]; //Масив в який записуватимется число в зворотному порядку
        char resultsq[SIZE][LENTH]; //Масив з результатом виконання завдання
        char units[COUNT][LENTH] = {" one"," two"," tree"," four"," five"," six"," seven"," eigth"," nine","zero"}; //Одиниці
        char dozensUnder20[COUNT][LENTH] = {" eleven"," twelve"," thirteen"," fourteen"," fifteen"," sixteen"," seventeen"," eighteen"," nineteen"," ten"}; //Числа від 11 до 19
        char dozens[COUNT][LENTH] = {" twenty"," thirty"," forty"," fifty"," sixty"," seventy"," eighty"," ninety"}; //Десятки
        char hundreds[COUNT][LENTH] = {" one hundred"," two_hundred"," tree hundred"," four hundred"," five hundred"," six hundred"," seven hundred"," eigth hundred"," nine hundred"}; //Сотні
        char thouthens[COUNT][LENTH] = {"one thousand","two thousand","tree thousand","four thousand","five thousand","six thousand","seven thousand","eigth thousand","nine thousand"}; //Тисячі
        //Цикл розподілу числа в масив
        for (int i = SIZE-1; i >= 0; i--) {
                       b[i] = num % 10;
                       num = num / 10;
               }
               //Перевірка на те, чи не дорівнює число нулю
               if (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0) {
                       for (int j = 0; j < LENTH; j++) {
                               resultsq[0][j] = units[9][j];
                               resultsq[1][j] = ' ';
                               resultsq[2][j] = ' ';
                               resultsq[3][j] = ' ';
                       }
               }else{
                       for (int i = 0; i < SIZE; i++) {
                               //Цикл підстановки тисяч
                               if (i == 0) {
                                       if(b[i] == 0) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       resultsq[i][j] = '\0';
                                               }
                                       }else{
                                               for (int j = 0; j < LENTH; j++) {
                                                       resultsq[i][j] = thouthens[b[i]-1][j];
                                               }
                                       }
                               }
                               //Цикл підстановки сотень
                               if (i == 1) {
                                       if(b[i] == 0) {
                                                for (int j = 0; j < LENTH; j++) {
                                                        resultsq[i][j] = '\0';
                                                }
                                       }else{
                                                for (int j = 0; j < LENTH; j++) {
                                                        resultsq[i][j] = hundreds[b[i]-1][j];
                                                }
                                       }
                               }
                               //Цикл підстановки десятків
                               if (i == 2) {
                                       if(b[i] == 1) {
                                                for (int j = 0; j < LENTH; j++) {
                                                        resultsq[i][j] = dozensUnder20[b[i + 1] - 1][j];
                                                }
                                       }else{
                                                if(b[i] == 0) {
                                                        for (int j = 0; j < LENTH; j++) {
                                                                resultsq[i][j] = '\0';
                                                               }
                                                }else{
                                                        for (int j = 0; j < LENTH; j++) {
                                                                resultsq[i][j] = dozens[b[i]-2][j];
                                                        }
                                                }
                                       }
                               }
                               //Цикл підстановки одиниць
                               if (i == 3 && b[i-1] == 1) {
                                       for (int j = 0; j < LENTH; j++) {
                                                                       resultsq[i][j] = '\0';
                                       }
                               }else if (i == 3) {
                                       if(b[i] == 0) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       resultsq[i][j] = '\0';
                                               }
                                       }else{

                                               for (int j = 0; j < LENTH; j++) {
                                                       resultsq[i][j] = units[b[i] - 1][j];
                                               }
                                       }
                               }
                       }
               }
               for (int i = 0; i < RESSIZE; i++) {
                       result[i] = resultsq[0][i];

               }
               for (int i = 0; i < RESSIZE; i++) {
                       if (result[i] == '\0') {
                               for (int j = i; j < RESSIZE; j++){
                                       result[j] = result[j+1];
                               }
                               i--;
                       }
                       result[i] = (result[i] == 'U') ? ' ' : result[i];
               }

}
