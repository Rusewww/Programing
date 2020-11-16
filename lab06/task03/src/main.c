int main() {
       #define LENTH 20
       #define SIZE 4
       #define COUNT 10
       int num = 4116;
       int b[SIZE];
       char result[SIZE][LENTH];
       char units[COUNT][LENTH] = {"one","two","tree","four","five","six","seven","eigth","nine","zero"};
       char dozensUnder20[COUNT][LENTH] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","ten"};
       char dozens[COUNT][LENTH] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
       char hundreds[COUNT][LENTH] = {"one_hundred","two_hundred","tree_hundred","four_hundred","five_hundred","six_hundred","seven_hundred","eigth_hundred","nine_hundred"};
       char thouthens[COUNT][LENTH] = {"one_thousand","two_thousand","tree_thousand","four_thousand","five_thousand","six_thousand","seven_thousand","eigth_thousand","nine_thousand"};
       for (int i = SIZE-1; i >= 0; i--) {
               b[i] = num % 10;
               num = num / 10;
       }
       if (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0) {
               for (int j = 0; j < LENTH; j++) {
                       result[0][j] = '\0';
                       result[1][j] = '\0';
                       result[2][j] = '\0';
                       result[3][j] = units[9][j];
               }
       }else{
               for (int i = 0; i < SIZE; i++) {
                       if (i == 0) {
                               if(b[i] == 0) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = '\0';
                                       }
                               }else{                
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = thouthens[b[i]-1][j];
                                       }
                               }
                       }
                               if (i == 1) {
                                       if(b[i] == 0) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = '\0';
                                               }
                                       }else{                
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[b[i]-1][j];
                                               }   
                                       }
                               }
                               if (i == 2) {
                                       if(b[i] == 1) {                
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = dozensUnder20[b[i + 1] - 1][j];
                                               }     
                                       }else{
                                               if(b[i] == 0) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = '\0';
                                                       }
                                               }else{                
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[b[i]-2][j];
                                                       }
                                               }                
                                       }       
                               }                
                       if (i == 3 && b[i-1] == 1) {
                               for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = '\0';
                               }
                       }else if (i == 3) {
                               if(b[i] == 0) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = '\0';
                                       }
                               }else{                
                                       
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[b[i] - 1][j];
                                       }
                               }
                       }
               }
       }
       return 0;
}              
