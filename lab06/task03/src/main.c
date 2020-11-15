int main() {
       #define LENTH 20
       #define SIZE 4
       #define COUNT 10
       int num = 4113;
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
                                       result[3][j] = units[9][j];
                               }
               }else{
                       for (int i = 0; i < SIZE; i++) {
                               if (i == 0) {
                                       if (b[i] == 9) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[8][j];
                                               }
                                       }else if (b[i] == 8) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[7][j];
                                               }
                                       }else if (b[i] == 7) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[6][j];
                                               }
                                       }else if (b[i] == 6) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[5][j];
                                               }
                                       }else if (b[i] == 5) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[4][j];
                                               }
                                       }else if (b[i] == 4) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[3][j];
                                               }
                                       }else if (b[i] == 3) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[2][j];
                                               }
                                       }else if (b[i] == 2) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[1][j];
                                               }
                                       }else if (b[i] == 1) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = thouthens[0][j];
                                               }
                                       }else{
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = '\0';
                                               }        
                                       }
                               }
                               if (i == 1) {
                                       if (b[i] == 9) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[8][j];
                                               }
                                       }else if (b[i] == 8) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[7][j];
                                               }
                                       }else if (b[i] == 7) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[6][j];
                                               }
                                       }else if (b[i] == 6) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[5][j];
                                               }
                                       }else if (b[i] == 5) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[4][j];
                                               }
                                       }else if (b[i] == 4) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[3][j];
                                               }
                                       }else if (b[i] == 3) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[2][j];
                                               }
                                       }else if (b[i] == 2) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[1][j];
                                               }
                                       }else if (b[i] == 1) {
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = hundreds[0][j];
                                               }
                                       }else{
                                               for (int j = 0; j < LENTH; j++) {
                                                       result[i][j] = '\0';
                                               }        
                                       }
                               }
                               if (i == 2) {
                                       if(b[i] == 1) {
                                               if (b[i+1] == 9) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[8][j];
                                                       }
                                               }else if (b[i + 1] == 8) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[7][j];
                                                       }
                                               }else if (b[i + 1] == 7) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[6][j];
                                                       }
                                               }else if (b[i + 1] == 6) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[5][j];
                                                       }
                                               }else if (b[i + 1] == 5) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[4][j];
                                                       }
                                               }else if (b[i + 1] == 4) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[3][j];
                                                       }
                                               }else if (b[i + 1] == 3) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[2][j];
                                                       }
                                               }else if (b[i + 1] == 2) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[1][j];
                                                       }
                                               }else if (b[i + 1] == 1) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[0][j];
                                                       }
                                               }else if (b[i + 1] == 0) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozensUnder20[9][j];
                                                       }        
                                               break;
                                               }else{
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = '\0';
                                                       } 
                                               }       
                                       }else{
                                               if (b[i] == 9) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[7][j];
                                                       }
                                               }else if (b[i] == 8) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[6][j];
                                                       }
                                               }else if (b[i] == 7) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[5][j];
                                                       }
                                               }else if (b[i] == 6) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[4][j];
                                                       }
                                               }else if (b[i] == 5) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[3][j];
                                                       }
                                               }else if (b[i] == 4) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[2][j];
                                                       }
                                               }else if (b[i] == 3) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[1][j];
                                                       }
                                               }else if (b[i] == 2) {
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = dozens[0][j];
                                                       }
                                               }else{
                                                       for (int j = 0; j < LENTH; j++) {
                                                               result[i][j] = '\0';
                                                       } 
                                               }                
                                       }       
                               }                
                       if (i == 3 && b[i-1] > 1) {
                               if (b[i] == 9) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[8][j];
                                       }
                               }else if (b[i] == 8) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[7][j];
                                       }
                               }else if (b[i] == 7) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[6][j];
                                       }
                               }else if (b[i] == 6) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[5][j];
                                       } 
                               }else if (b[i] == 5) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[4][j];
                                       }
                               }else if (b[i] == 4) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[3][j];
                                       }
                               }else if (b[i] == 3) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[2][j];
                                       }
                               }else if (b[i] == 2) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[1][j];
                                       }
                               }else if (b[i] == 1) {
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = units[0][j];
                                       }
                               }else{
                                       for (int j = 0; j < LENTH; j++) {
                                               result[i][j] = '\0';
                                       }        
                               }
                       }
               }
       }
       return 0;
}
               
