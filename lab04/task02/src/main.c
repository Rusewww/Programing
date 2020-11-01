int main() {
        float num = 123.456 ;
        float drob = num - (int)num ;
        float risn;
        int a = num ;
        int roz = 1 ;
        while (a != 0)
        {
             roz *= 10;
             a /=10;
        }
        drob *= roz ;
        if ((int)num != 0) {
            risn = drob / (int)num ;
            risn = risn * 100 ;
            risn = (int)risn ;
            risn /= 100 ;
        } else {
            risn = 0 ; 
        }   
        return 0 ;
}
        
