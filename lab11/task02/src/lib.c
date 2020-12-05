//
// Created by Rusewww on 12/5/20.
//
#include <stdlib.h>
void randomizeWithMin(int arr[], int size, int max) {
        for (int i = 0; i < size; ++i) {
                arr[i] = (rand() % (max * 2) + 1) - max;
        }
}

int findMaxLenght(int array[], int size){
        int maxHead = -1;
        int curHead = -1;
        int maxSum = 0;
        int curSum = 0;
        int maxLength = 0 ;
        int curLength = 0;
        for (int i = 0; i <= size; i++) {
                if (i == size || array[i] <= 0) {
                        if (curHead >= 0) {
                                if (curSum > maxSum) {
                                        maxHead = curHead;
                                        maxLength = curLength;
                                        maxSum = curSum;
                                }
                                curHead = -1;
                                curLength = 0;
                                curSum = 0;
                        }
                }else{
                        if (curHead < 0) {
                                curHead = i;
                        }
                        curLength += 1;
                        curSum += array[i];
                }
        }
        return (maxLength);
}

int findMaxHead(int array[], int size) {
        int maxHead = -1;
        int curHead = -1;
        int maxSum = 0;
        int curSum = 0;
        int maxLength = 0;
        int curLength = 0;
        for (int i = 0; i <= size; i++) {
                if (i == size || array[i] <= 0) {
                        if (curHead >= 0) {
                                if (curSum > maxSum) {
                                        maxHead = curHead;
                                        maxLength = curLength;
                                        maxSum = curSum;
                                }
                                curHead = -1;
                                curLength = 0;
                                curSum = 0;
                        }
                } else {
                        if (curHead < 0) {
                                curHead = i;
                        }
                        curLength += 1;
                        curSum += array[i];
                }
        }
        return (maxHead);
}