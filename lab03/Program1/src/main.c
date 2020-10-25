int main() {
    const float firstResistorResistance= 0.5; // Опір першого резистора
    const float secondResistorResistance= 0.5;// Опір другого резистора
    const float thirdResistorResistance= 0.5;// Опір трерього резистора
    float totalResistance=(firstResistorResistance*secondResistorResistance*thirdResistorResistance)/(secondResistorResistance*thirdResistorResistance+firstResistorResistance*thirdResistorResistance+firstResistorResistance*secondResistorResistance);//Загальний опір кола та формула його обчислення
    return 0;
}
