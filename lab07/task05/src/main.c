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
int main () {
        float num = 26;
        float result = root(num);
        return 0;
}
