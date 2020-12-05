//
// Created by Rusewww on 12/5/20.
//
#include <malloc.h>
#include <stdlib.h>
void randomize(int arr[], int size, int max) {
        for (int i = 0; i < size; i++) {
                arr[i] = rand() % max;
        }
}

int sizeCheck(int arr[], int size) {
        int n = size;
        for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                        if (arr[i] == arr[j]) {
                                n = n - 1;
                        }
                }
        }
        int result = n * 2;
        return (result);
}

void findFrequency(int* res, int n, int arr[], int size){
        int cor = 0;
        for (int i = 0; i < size; i++) {
                for (int k = 0; k < size; k++) {
                        for (int j = i - 1; j > 0; j--){
                                if (arr[j] == arr[i]) {
                                        i++;
                                        cor++;
                                }
                        }
                        if (arr[i] != arr[k]) {
                                *(res + (i - cor) * 2) = arr[i];
                        }else{
                                *(res + ((i - cor) * 2) + 1) += 1;
                        }
                }
        }
}