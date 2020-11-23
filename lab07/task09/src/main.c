/**
Функція main: задає масив та його розміри, і передає все до функції quantity.
*/
int main() {
        #define SIZE 60// Максимальна кількість символів
        char a[SIZE] = {'T','h','i','s',' ',' ',' ','i','s',' ','a',' ','p','r','o','g','r','a','m',' ',' ','t','h','a','t',' ','s','e','a','r','c','h',' ','t','h','e',' ','w','o','r','d','s'}; //Заданий масив з текстом
        int quantityOfWords = 0;
        quantityOfWords = quantity(a, SIZE, quantityOfWords);
        return 0;
}
/**
Функція quantity: рахує кількість слів в строці.
*/
int quantity(char a[], int size, int quantityOfWords) {
        if (a[0] == ' ' || a[0] == '\0') {
                quantityOfWords = 0;
        }else{
                quantityOfWords = 1;
        }
        for (int i = 0; i <= size; i++) {
                if (a[i] == ' ' && a[i + 1] != ' ') {
                        quantityOfWords += 1;
                }
        }
        return (quantityOfWords);
}
