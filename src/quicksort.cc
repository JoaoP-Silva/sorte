#include "quicksort.h"

//Methods from Standard recursive quicksort
void quicksort::partitionStd(int* array, int left, int right, int* i, int* j,
                             int* keysCmp, int* regCpy){
    int pvt, aux;
    *i = left; *j = right;
    pvt = array[(int)(*i + *j)/2];
    do{
        while(pvt > array[*i]){ (*i)++; (*keysCmp)++;}
        while(pvt < array[*j]){ (*j)--; (*keysCmp)++;}
        if( *i <= *j ){
            (*regCpy)++;
            aux = array[*i];
            array[*i] = array[*j];
            array[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i <= *j);
}

void quicksort::quicksortStd(int* array, int arrSize, int* keysCmp, int* regCpy){
    *keysCmp = 0; *regCpy = 0;
    quicksort::quicksortStdR(0, arrSize-1, array, keysCmp, regCpy);
}

void quicksort::quicksortStdR(int left, int right, int* array, int* keysCmp, int* regCpy){
    int i, j;
    quicksort::partitionStd(array, left, right, &i, &j, keysCmp, regCpy);
    if(left < j){ quicksort::quicksortStdR(left, j, array, keysCmp, regCpy); }
    if (right > i){ quicksort::quicksortStdR(i, right, array, keysCmp, regCpy); }
}



//Methods from quicksort median
void quicksort::partitionMedian(int* array, int left, int right, int* i, int* j, int k,
                                int* keysCmp, int* regCpy){
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
        int subKeys, subRegs;
        quicksort::quicksortStd(subArray, k, &subKeys, &subRegs);
        *keysCmp += subKeys; *regCpy += subRegs;

        pvt = subArray[k/2];
        delete subArray;
    }
    else { 
        pvt = array[(int)(*i + *j)/2]; 
    }
    do{
        while(pvt > array[*i]){ (*i)++;  (*keysCmp)++;}
        while(pvt < array[*j]){ (*j)--;  (*keysCmp)++;}
        if( *i <= *j ){
            (*regCpy)++;
            aux = array[*i];
            array[*i] = array[*j];
            array[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void quicksort::quicksortMedian(int* array, int arrSize, int k, int* keysCmp, int* regCpy){
    *keysCmp = 0; *regCpy = 0;
    quicksort::quicksortMedianR(0, arrSize-1, k, array, keysCmp, regCpy);
}

void quicksort::quicksortMedianR(int left, int right, int k, int* array,
                                 int* keysCmp, int* regCpy){
    int i, j;
    quicksort::partitionMedian(array, left, right, &i, &j, k, keysCmp, regCpy);
    if(left < j){ quicksort::quicksortMedianR(left, j, k,array, keysCmp, regCpy); }
    if (right > i){ quicksort::quicksortMedianR(i, right, k, array, keysCmp, regCpy); }
}


//Methods from recursive quicksort mixed with selectionsort
void quicksort::quicksortSelection(int* array, int arrSize, int m, int* keysCmp, int* regCpy){
    keysCmp = 0; regCpy = 0;
    quicksort::quicksortSelectionR(0, arrSize-1, m,array, keysCmp, regCpy);
}

void quicksort::quicksortSelectionR(int left, int right, int m, int* array,
                                    int* keysCmp, int* regCpy){
    int i, j;
    if(right - left <= m){
        quicksort::selectionSort(array, left, right, keysCmp, regCpy);
    }else{
        quicksort::partitionStd(array, left, right, &i, &j, keysCmp, regCpy);
        if(left < j){ quicksort::quicksortSelectionR(left, j, m, array, keysCmp, regCpy); }
        if (right > i){ quicksort::quicksortSelectionR(i, right, m, array, keysCmp, regCpy); }
    }
}

void quicksort::selectionSort(int* array, int left, int right,
                              int* keysCmp, int* regCpy){
    for(int i = left; i<= right; i++){
        int less = array[i];
        for(int j = i + 1; j<= right; j++){
            (*keysCmp)++;
            if(array[j] < less){
                (*regCpy)++;
                int aux = less;
                less = array[j];
                array[j] = aux;
            }
        }
    }
}

//Methods from quicksortIterative
void quicksort::quisortIterative(int* array, int arrSize, int* keysCmp, int* regCpy){
    *keysCmp = 0; *regCpy = 0;
    Stack s;
    int right = arrSize - 1, left = 0, i , j;
    s.push(right);
    s.push(left);
    do{
        if(right > left){
            quicksort::partitionStd(array, left, right, &i, &j, keysCmp, regCpy);
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
void quicksort::quisortSmartStack(int* array, int arrSize, int* keysCmp, int* regCpy){
    *keysCmp = 0; *regCpy = 0;
    Stack s;
    int right = arrSize - 1, left = 0, i , j;
    s.push(right);
    s.push(left);
    do{
        if(right > left){
            quicksort::partitionStd(array, left, right, &i, &j, keysCmp, regCpy);
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