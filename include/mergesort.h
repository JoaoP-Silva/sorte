#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

/**Class to alocate all heapsort methods.
 * This class has only static methods. **/
class mergesort{
    private:
        //Private method merge. Is called by mergesort
        static void merge(int* array, int left, int mid, int right, int* keysCmp, int* regCpy);
        
        static void mergeSortR(int* array, int left, int right, int* keysCmp, int* regCpy);

    public:
        //Public method mergeSort
        static void mergeSort(int* array, int arrSize, int* keysCmp, int* regCpy);
};

#endif