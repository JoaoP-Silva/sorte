#include "heapsort.h"



//Heapsort methods
void heapsort::build(int* array, int arrSize, int* keysCmp, int* regCpy){
    int left = arrSize/2;
    while(left >= 1){
        left--;
        rebuild(left, arrSize - 1, array, keysCmp, regCpy);
    }
}

void heapsort::rebuild(int left, int right, int* array, int* keysCmp, int* regCpy){
    int i, j, x;
    i = left; j = i*2 + 1;
    x = array[i];
    while(j <= right){
        (*keysCmp)++;
        if(j < right){
            if(array[j] < array[j+1]){ j++;}
        }if( x >= array[j]){ break; }
        (*regCpy)++;
        array[i] = array[j];
        i = j;
        j = i*2 + 1;
    }
    array[i] = x;
}


void heapsort::heapSort(int* array, int arrSize, int* keysCmp, int* regCpy){
    *keysCmp = 0; *regCpy = 0;
    int left = 0, right = arrSize - 1, x;
    heapsort::build(array, arrSize, keysCmp, regCpy);
    while(right > 0){
        (*regCpy)++;
        x = array[0];
        array[0] = array[right];
        array[right] = x;
        right --;
        heapsort::rebuild(left, right, array, keysCmp, regCpy);
    }
}