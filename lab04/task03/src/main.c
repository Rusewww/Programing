// Розставити числа від меншого до найбільшого
int main() {
        int k = 4 ; // Перше число
        int m = 5 ; // Друге число
        int n = 1 ; // Третє число
        int reserve = 0 ; // Резерв чисел
        // Порівняння першого і другого чисел
        if (k > m) {
                reserve = k ;
                k = m ;
                m = reserve ;  
        }
        // Порівняння другого і третього чисел
        if (m > n) {
                reserve = m ;
                m = n ;
                n = reserve ; 
        }
        // Порівняння першого і другого чисел х2
        if (k > m) {
                reserve = k ;
                k = m ;
                m = reserve ; 
        }
        return 0 ;
}
