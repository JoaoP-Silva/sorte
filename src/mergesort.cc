#include "mergesort.h"

//Mergesort methods
void mergesort::mergeSort(int* array, int arrSize, int* keysCmp, int*regCpy){
    int left = 0; int right = arrSize - 1;
    *keysCmp = 0; *regCpy = 0;
    mergesort::mergeSortR(array, left, right, keysCmp, regCpy);
}

void mergesort::mergeSortR(int* array, int left, int right, int* keysCmp, int* regCpy){
    if(left < right){
        int mid = (left + right)/2;
        mergesort::mergeSortR(array, left, mid, keysCmp, regCpy);
        mergesort::mergeSortR(array, mid + 1, right, keysCmp, regCpy);
        mergesort::merge(array, left, mid, right, keysCmp, regCpy);
    }
}

void mergesort::merge(int* array, int left, int mid, int right,
                            int* keysCmp, int* regCpy){
    
    int nl = mid - left + 1; 
    int nr = right - mid;
    int* valuesL = new int[nl];
    int* valuesR = new int[nr];

    for(int i =0; i < nl; i++){
        valuesL[i] = array[left + i];
    }
    for(int j =0; j < nr; j++){
        valuesR[j] = array[mid + j + 1];
    }

    int i=0, j=0, k=left;
    while(i < nl && j < nr){
        (*keysCmp)++;
        (*regCpy)++;
        if(valuesL[i] <= valuesR[j]){
            array[k] = valuesL[i];
            i++;
        }else{
            array[k] = valuesR[j];
            j++;
        }
        k++;
    }
   
    for(; i < nl; i++){
        (*regCpy)++;
        array[k] = valuesL[i];
        k++;
    }
    for(; j < nr; j++){
        (*regCpy)++;
        array[k] = valuesR[j];
        k++;
    }

    delete[] valuesL;
    delete[] valuesR;
}