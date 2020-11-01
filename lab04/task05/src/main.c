int main() {
        float x = 1 ;
        float y ;
        if (x <= -1) {
            y = -x - 1 ;
        }
        if (x > -1 && x <= 0) { 
            y = x + 1 ;
        }  
        if (x > 0 && x <= 1) {
            y = -x + 1 ;
        }
        if (x > 1) { 
            y = x - 1 ;
        }    
        return 0 ;
}
