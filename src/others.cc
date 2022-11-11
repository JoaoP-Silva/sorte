#include "others.h"

int sortParser(char* argv[], int* randSeed,string& input, string& output){

    //If some parameter is wrong, return -1;
    string s = argv[1];
    if(s != "quicksort"){
        return 0;
    }

    s = argv[2];
    if(s != "-v"){
        return 0;
    }

    string v = argv[3];
    if(v == "1"){
        //Invoke default quicksort
        s = argv[4];
        if( s != "-s"){ return 0; }
        s = argv[6];
        if( s != "-i"){ return 0; }
        s = argv[8];
        if( s != "-o"){ return 0; }
        //If all input flags are correct, return the sort method and modifies i/o filenames
        *randSeed = atoi(argv[5]);
        input = argv[7];
        output = argv[9];
        return 1;
    }else if(v == "2"){
        //Invoke median quicksort
        s = argv[4];
        if( s != "-k"){ return 0; }
        s = argv[6];
        if( s != "-s"){ return 0; }
        s = argv[8];
        if( s != "-i"){ return 0; }
        s = argv[10];
        if( s != "-o"){ return 0; }
        //If all input flags are correct, return the sort method and modifies i/o filenames
        *randSeed = atoi(argv[7]);
        input = argv[9];
        output = argv[11];
        return 2;
    }else if(v == "3"){
        //Invoke selection quicksort
        s = argv[4];
        if( s != "-m"){ return 0; }
        s = argv[6];
        if( s != "-s"){ return 0; }
        s = argv[8];
        if( s != "-i"){ return 0; }
        s = argv[10];
        if( s != "-o"){ return 0; }
        //If all input flags are correct, return the sort method and modifies i/o filenames
        *randSeed = atoi(argv[7]);
        input = argv[9];
        output = argv[11];
        return 3;
    }else if(v == "4"){
        //Invoke iterative quicksort
        s = argv[4];
        if( s != "-s"){ return 0; }
        s = argv[6];
        if( s != "-i"){ return 0; }
        s = argv[8];
        if( s != "-o"){ return 0; }
        //If all input flags are correct, return the sort method and modifies i/o filenames
        *randSeed = atoi(argv[5]);
        input = argv[7];
        output = argv[9];
        return 4;
    }else if(v == "5"){
        //Invoke smart stack quicksort
        s = argv[4];
        if( s != "-s"){ return 0; }
        s = argv[6];
        if( s != "-i"){ return 0; }
        s = argv[8];
        if( s != "-o"){ return 0; }
        //If all input flags are correct, return the sort method and modifies i/o filenames
        *randSeed = atoi(argv[5]);
        input = argv[7];
        output = argv[9];
        return 5;
    }else{
        //Input error
        return 0;
    }
}

int* genRandInt(int N, int seed){
    srand(seed);
    int* array = new int[N];
    for(int i = 0; i<N; i++){
        array[i] = rand();
    }
    return array;
}


int callSort(int res, char* argv[], int seed, string input, string output){
    ifstream inFile;
    inFile.open(input);
    if(!inFile.is_open()){
        cerr << "File error. "<< input <<" Not found\n";
        return 0;
    }

    int N;
    while(inFile >> N){
        cout << "Entrou no while\n";
        switch (res)
        {
            case 1:
            {
                int* array = genRandInt(N, seed);

                //Invoke default quicksort
                quicksort::quicksortStd(array, N);
                break;
            }

            case 2:
            {
                //Invoke median quicksort
                break;
            }
            case 3:
            {    //Invoke selection quicksort
                break;
            }
            case 4:
            {
                //Invoke iterative quicksort
                break;
            }
            case 5:
            {
                //Invoke smart stack quicksort
                break;
            }    
        }
    }
    
}