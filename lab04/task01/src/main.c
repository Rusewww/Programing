// За заданим радіусом r та командою користувача обчислити:
// 'l' - ловжину кола
// 's' - площу круга
// 'v' - об'єм кулі
int main() {
        #define PI 3.14 ; // Число Пі
        const float r = 5 ; // Радіус 
        char command = 's' ; // Команда користувача
        float result ; 
        if (command == 'l') {
                result = 2 * r * PI ;  // Виконання команди 'l' 
        }
        if (command == 's') {
                result = r * r * PI ; // Виконання команди 's'
        }
        if (command == 'v') {
                result = 4 * r * r * r / 3 * PI ; // Виконання команди 'v'
        }
        return 0 ;
}
 
