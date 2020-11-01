int main() {
        int k = 4 ;
        int m = 5 ;
        int n = 1 ;
        int flag = 0 ;
        if (k > m) {
            flag = k ;
            k = m ;
            m = flag ;
        }
        if (m > n) {
            flag = m ;
            m = n ;
            n = flag ;
        }
        if (k > m) {
            flag = k ;
            k = m ;
            m = flag ;
        }
        return 0 ;
}
