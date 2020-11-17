//Перетворити число в рядок
int main() {
       #define LENTH 15 //Максимальна довжина одного слова
       #define SIZE 4 //Довжина масиву
       #define RESSIZE 60
       #define COUNT 10 //Кількість слів в масиві
       int num = 4116; //Задане число
       int b[SIZE]; //Масив в який записуватимется число в зворотному порядку
       char result [RESSIZE];
       char resultsq[SIZE][LENTH]; //Масив з результатом виконання завдання
       char units[COUNT][LENTH] = {"one","two","tree","four","five","six","seven","eigth","nine","zero"}; //Одиниці
       char dozensUnder20[COUNT][LENTH] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","ten"}; //Числа від 11 до 19
       char dozens[COUNT][LENTH] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"}; //Десятки 
       char hundreds[COUNT][LENTH] = {"one_hundred","two_hundred","tree_hundred","four_hundred","five_hundred","six_hundred","seven_hundred","eigth_hundred","nine_hundred"}; //Сотні
       char thouthens[COUNT][LENTH] = {"one_thousand","two_thousand","tree_thousand","four_thousand","five_thousand","six_thousand","seven_thousand","eigth_thousand","nine_thousand"}; //Тисячі
       //Цикл розподілу числа в масив
       for (int i = SIZE-1; i >= 0; i--) {
               b[i] = num % 10;
               num = num / 10;
       }
       //Перевірка на те, чи не дорівнює число нулю
       if (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0) {
               for (int j = 0; j < LENTH; j++) {
                       resultsq[0][j] = ' ';
                       resultsq[1][j] = ' ';
                       resultsq[2][j] = ' ';
                       resultsq[3][j] = units[9][j];
               }
       }else{
               for (int i = 0; i < SIZE; i++) {
                       //Цикл підстановки тисяч
                       if (i == 0) {
                               if(b[i] == 0) {
                                       for (int j = 0; j < LENTH; j++) {
                                               resultsq[i][j] = ' ';
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
                                                resultsq[i][j] = ' ';
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
                                                        resultsq[i][j] = ' ';
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
                                                               resultsq[i][j] = ' ';
                               }
                       }else if (i == 3) {
                               if(b[i] == 0) {
                                       for (int j = 0; j < LENTH; j++) {
                                               resultsq[i][j] = ' ';
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
       return 0;
}              
