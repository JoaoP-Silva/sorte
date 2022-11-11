#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sstack.h"

/**Class to alocate all quicksort methods.
 * This class has only static methods. **/
class quicksort{
    private:
        /**Define the pivot as the central element of the partition
         * Is used in method quicksort()**/
        static void partitionStd(int* array, int left, int right, int* i, int* j);
        //Recursive call to quicksortStd
        static void quickSortStdR(int left, int right, int* array);

    public:
        //Mehods related to the standart recursive quicksort.
        static void quicksortStd(int* array, int arrSize);
};

#endif