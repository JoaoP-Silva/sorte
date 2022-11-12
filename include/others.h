#ifndef OTHERS_H
#define OTHERS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sys/resource.h>

#include "quicksort.h"

using namespace std;

/**Function to parse the input and return a int related to the sort method.
* Modifies the randSeed, and the strings input and output to the file names. **/ 
int sortParser(char* argv[], int* randSeed,string& input, string& output);

//Generates a array with N random integers from 0 to RAND_MAX
int* genRandInt(int N, int seed);

//Run experiments and write the results on the output
int callSort(int res, char* argv[], int seed,string input, string output);


#endif