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

        /**If the partition have less elements than m, sort by selection.
         * Is used in method quicksortSelection()**/
        static void partitionSelection(int* array, int left, int right, int* i, int* j);
        /**Recursive call to quicksortSelection
         * If the partition have less elements than m, sort by selection.**/
        static void quicksortSelectionR(int left, int right, int m,int* array);
        //Sort a partition of an array by selection
        static void selectionSort(int* array, int left, int right);

    public:
        //Recursive standard quicksort.
        static void quicksortStd(int* array, int arrSize);

        //Recursive median quicksort
        static void quicksortMedian(int* array, int arrSize, int k);

        //Recursive quicksort mixed with selectionsort
        static void quicksortSelection(int* array, int arrSize, int m);


};

#endif