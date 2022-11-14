#include "others.h"
#include <sys/resource.h>

using namespace std;


int main(int argc, char* argv[]){
    
    string input, output;
    int randSeed;
    //Generate a res related to the sort method
    int res = sortParser(argv, &randSeed, input, output);
    if(!res){
        cerr << "Input error.\n";
        return -1;
    }
    //Realize an experiment based on the response of the sortParser method.
    //Get data from input file and write the results on output.
    callSort(res, argv, randSeed, input, output);
    return 0;
}