// Обчислення значення y для графіку y(х) при заданому числі х.
int main() {
        const float x = 1 ; // Число х
        float y ; // Змінна у
        // Заданий графік:
        if (x <= -1) {
                y = -x - 1 ;
        } else if (x > -1 && x <= 0) { 
                y = x + 1 ;
        } else if (x > 0 && x <= 1) {
                y = -x + 1 ;
        } else if (x > 1) { 
                y = x - 1 ;
        }    
        return 0 ;
}
