int main(){
        #define SIZE 50
        char a[SIZE] = {'T','h','i','s',' ',' ',' ','i','s',' ','a',' ','p','r','o','g','r','a','m',' ',' ','t','h','a','t',' ','s','e','a','r','c','h',' ','t','h','e',' ','w','o','r','d','s'};
        int quantityOfWords;
        if (a[0] == ' ' || a[0] == '\0') {
                quantityOfWords = 0;
        }else{ 
                quantityOfWords = 1;
        }
        for (int i = 0; i <= SIZE; i++) {
                if (a[i] == ' ' && a[i + 1] != ' ') {
                        quantityOfWords += 1; 
                        }
        }
        return 0;
}
