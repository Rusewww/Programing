int main() {
        #define PI 3.14 ; 
        const float r = 5 ;
        char command = 'v' ;
        float result = 0 ;
        if (command == 'l') {
            result = 2 * r * PI ;
        }
        if (command == 'r') {
            result = r * r * PI 
        }
        if (command == 'v') {
            result = 4 * r * r * r / 3 * PI
        }
        return 0 ;
}
 
