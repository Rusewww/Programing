int main() {
        const float res1 = 0.5 ; // Опір першого резистора
        const float res2 = 0.5 ; // Опір другого резистора
        const float res3 = 0.5 ; // Опір третього резистора
        float part1 = res1 * res2 * res3 ; //Перша частина формули
        float part2 = res2 * res3 + res1 * res3 + res1 * res2 ; //Друга частина формули
        float totalResistance = part1 / part2 ; //Загальний опір кола
        return 0;
}
