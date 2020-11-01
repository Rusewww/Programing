int main() {
        const float x = -5 ;
        float y ;
        if (x <= -1) {
            y = -1 / x ;
        }
        if (x > -1 && x < 1) {
            y = x * x ;
        }    
        if (x > 1) { 
            y = 1;
        }           
        return 0 ;
}
