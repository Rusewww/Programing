#include <stdlib.h>
#include <time.h>
/**
Функція root: без допомоги зовнішніх бібліотек, отримує корінь заданого числа.
*/
float root(float num) {
        #define EPS 0.01 //Єпсілон точності
        float root = num /2 ;
        while (((root * root)- num)>= EPS || (num -(root * root))>= EPS ) {
                if (root * root > num) {
                        root -= root / 2;
                }else{
                        root += root / 2;
                }
        }
        return (root);
}
/**
Функція main: формує 1 випадкове число < 100, і передає його до функції root.
*/
int main () {
        srand(time(NULL));
        int rand_max = 100;
        const float num = rand() % rand_max + 1;
        float result = root(num);
        return 0;
}
