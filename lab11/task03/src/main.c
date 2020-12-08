//
// Created by Rusewww on 12/5/20.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
        #define SIZE 10
        float max = 50;
        float arr[SIZE];
        int count = 0;
        for (int i=0; i < SIZE; i++) {
                arr[i] = (float)(rand()) / 1000000000 * max / 2;
        }
        for (int i=0; i < SIZE - 2; i++) {
                if (arr[i + 1] > arr[i]) {
                        count += 1;
                }
        }
        return 0;
}
