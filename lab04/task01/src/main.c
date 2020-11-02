// За заданим радіусом r та командою користувача обчислити:
// 'l' - ловжину кола
// 's' - площу круга
// 'v' - об'єм кулі
int main() {
        #define PI 3.14 // Число Пі
        const float r = 5 ; // Радіус 
        char command = 's' ; // Команда користувача
        float result ; 
        switch(command) {
                case 'l' :
                        result = 2 * r * PI ;  // Виконання команди 'l' 
                break ;
                case 's' :
                        result = r * r * PI ; // Виконання команди 's'
                break ;
                case 'v' :   
                      result = 4 * r * r * r / 3 * PI ; // Виконання команди 'v'
                break ;
        }
        return 0 ;
}
 
