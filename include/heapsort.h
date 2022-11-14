#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>

/**Class to alocate all heapsort methods.
 * This class has only static methods. **/
class heapsort{
    private:
        //Build heap. Is called by heapsort
        static void rebuild(int left, int right, int* array, int* keysCmp, int* regCpy);
        //Rebuild heap. Is called by heapsort
        static void build(int* array, int arrSize, int* keysCmp, int* regCpy);

    public:
        //Public method heapSort
        static void heapSort(int* array, int arrSize, int* keysCmp, int* regCpy);
};

#endif