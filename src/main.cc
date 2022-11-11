#include "others.h"
#include "quicksort.h"
#include "sstack.h"
#include <sys/resource.h>

using namespace std;


int main(int argc, char* argv[]){
    
    string input, output;
    int randSeed;
    //Generate a res related to the sort method
    int res = sortParser( argv, &randSeed, input, output);
    if(!res){
        cout << "Input error.\n";
    }
    callSort(res, argv, randSeed, input, output);
    return 0;
}