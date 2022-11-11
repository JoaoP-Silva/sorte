#include "quicksort.h"

//Standard recursive quicksort implementation methods
void quicksort::partitionStd(int* array, int left, int right, int* i, int* j){
    int pvt, aux;
    *i = left; *j = right;
    pvt = array[(int)(*i + *j)/2];
    do{
        while(pvt > array[*i]){ (*i)++; }
        while(pvt < array[*j]){ (*j)--; }
        if( *i <= *j ){
            aux = array[*i];
            array[*i] = array[*j];
            array[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i <= *j);
}

void quicksort::quicksortStd(int* array, int arrSize){
    quicksort::quickSortStdR(0, arrSize-1, array);
}

void quicksort::quickSortStdR(int left, int right, int* array){
    int i, j;
    quicksort::partitionStd(array, left, right, &i, &j);
    if(left < j){ quicksort::quickSortStdR(left, j, array); }
    if (right > i){ quicksort::quickSortStdR(i, right, array); }
}