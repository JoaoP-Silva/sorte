#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sstack.h"
#include <cstdlib>

/**Class to alocate all quicksort methods.
 * This class has only static methods. **/
class quicksort{
    private:
        /**Define the pivot as the central element of the partition
         * Is used in method quicksortStd()**/
        static void partitionStd(int* array, int left, int right, int* i, int* j);
        //Recursive call to quicksortStd
        static void quicksortStdR(int left, int right, int* array);

        /**Define the pivot as the median of k elements
         * Is used in method quicksortMedian()**/
        static void partitionMedian(int* array, int left, int right, int* i, int* j, int k);
        //Recursive call to quicksortMedian
        static void quicksortMedianR(int left, int right, int k,int* array);

    public:
        //Recursive standard quicksort.
        static void quicksortStd(int* array, int arrSize);

        //Median recursive quicksort
        static void quicksortMedian(int* array, int arrSize, int k);

};

#endif