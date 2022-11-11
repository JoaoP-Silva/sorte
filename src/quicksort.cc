#include "quicksort.h"

//Standard recursive quicksort methods
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
    quicksort::quicksortStdR(0, arrSize-1, array);
}

void quicksort::quicksortStdR(int left, int right, int* array){
    int i, j;
    quicksort::partitionStd(array, left, right, &i, &j);
    if(left < j){ quicksort::quicksortStdR(left, j, array); }
    if (right > i){ quicksort::quicksortStdR(i, right, array); }
}



//Recursive quicksort median methods
void quicksort::partitionMedian(int* array, int left, int right, int* i, int* j, int k){
    int pvt, aux;
    *i = left;
    *j = right;
    if((*j - *i) >= k){
        int* subArray = new int[k];
        for(int it = 0; it<k; it++){
            //Gerates a random number from i to j
            int r = random() % *j + *i;
            subArray[it] = array[r];
        }
        quicksort::quicksortStd(subArray, k);
        pvt = subArray[k/2];
        delete subArray;
    }
    else { 
        pvt = array[(int)(*i + *j)/2]; 
    }
    //std::cout << "Ta chegando aq\n";
    do{
        while(pvt > array[*i]){ (*i)++; }
        while(pvt < array[*j]){ (*j)--; }
        if( *i <= *j ){
            aux = array[*i];
            array[*i] = array[*j];
            array[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void quicksort::quicksortMedian(int* array, int arrSize, int k){
    quicksort::quicksortMedianR(0, arrSize-1, k, array);
}

void quicksort::quicksortMedianR(int left, int right, int k, int* array){
    int i, j;
    quicksort::partitionMedian(array, left, right, &i, &j, k);
    if(left < j){ quicksort::quicksortMedianR(left, j, k,array); }
    if (right > i){ quicksort::quicksortMedianR(i, right, k, array); }
}