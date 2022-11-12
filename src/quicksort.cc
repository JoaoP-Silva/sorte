#include "quicksort.h"

//Methods from Standard recursive quicksort
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



//Methods from quicksort median
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


//Methods from recursive quicksort mixed with selectionsort
void quicksort::quicksortSelection(int* array, int arrSize, int m){
    quicksort::quicksortSelectionR(0, arrSize-1, m,array);
}

void quicksort::quicksortSelectionR(int left, int right, int m, int* array){
    int i, j;
    if(right - left <= m){
        quicksort::selectionSort(array, left, right);
    }else{
        quicksort::partitionStd(array, left, right, &i, &j);
        if(left < j){ quicksort::quicksortSelectionR(left, j, m, array); }
        if (right > i){ quicksort::quicksortSelectionR(i, right, m, array); }
    }
}

void quicksort::selectionSort(int* array, int left, int right){
    for(int i = left; i<= right; i++){
        int less = array[i];
        for(int j = i + 1; j<= right; j++){
            if(array[j] < less){
                int aux = less;
                less = array[j];
                array[j] = aux;
            }
        }
    }
}

//Methods from quicksortIterative
void quicksort::quisortIterative(int* array, int arrSize){
    Stack s;
    int right = arrSize - 1, left = 0, i , j;
    s.push(right);
    s.push(left);
    do{
        if(right > left){
            quicksort::partitionStd(array, left, right, &i, &j);
            s.push(j);
            s.push(left);
            left = i;
        }else{
            left = s.pop();
            right = s.pop();
        }
    }while(!s.isEmpty());
}


//Methods from Smart stack quicksort
void quicksort::quisortSmartStack(int* array, int arrSize){
    Stack s;
    int right = arrSize - 1, left = 0, i , j;
    s.push(right);
    s.push(left);
    do{
        if(right > left){
            quicksort::partitionStd(array, left, right, &i, &j);
            if((j - left) > (right - i)){
                s.push(j);
                s.push(left);
                left = i;
            }else{
                s.push(right);
                s.push(i);
                right = j;
            }
        }else{
            left = s.pop();
            right = s.pop();
        }
    }while(!s.isEmpty());
}