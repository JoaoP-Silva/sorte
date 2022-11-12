#include "others.h"

using namespace std;

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
    ofstream outFile;
    outFile.open(output, ios::app);
    if(!outFile.is_open()){
        cerr << "File error. "<< output <<" Not found or created\n";
        return 0;
    }
    ifstream inFile;
    inFile.open(input);
    if(!inFile.is_open()){
        cerr << "File error. "<< input <<" Not found\n";
        return 0;
    }

    int N;
    while(inFile >> N){
        int* array = genRandInt(N, seed);
        switch (res)
        {
            case 1:
            {
                int keysCmp, regCpy;
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                //Invoke default quicksort
                quicksort::quicksortStd(array, N, &keysCmp, &regCpy);

                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0){
                    cerr << "Getrusage failed\n";
                }
                utime = (double) resources.ru_utime.tv_sec
                + 1.e-6 * (double) resources.ru_utime.tv_usec;

                stime = (double) resources.ru_stime.tv_sec
                + 1.e-6 * (double) resources.ru_stime.tv_usec;

                total_time = utime+stime;
                outFile << "Total time std quicksort with N=" 
                << N << ": " << total_time <<endl;
                outFile << "Keys cmp : " << keysCmp << endl;
                outFile << "Registers copy : " << regCpy << endl;
                break;
            }

            case 2:
            {
                int keysCmp, regCpy;
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                //Invoke median quicksort
                int k = atoi(argv[5]);
                quicksort::quicksortMedian(array, N, k, &keysCmp, &regCpy);

                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0){
                    cerr << "Getrusage failed\n";
                }
                utime = (double) resources.ru_utime.tv_sec
                + 1.e-6 * (double) resources.ru_utime.tv_usec;

                stime = (double) resources.ru_stime.tv_sec
                + 1.e-6 * (double) resources.ru_stime.tv_usec;

                total_time = utime+stime;
                outFile << "Total time median quicksort with N=" 
                << N << "and k="<< k <<": " << total_time <<endl;
                outFile << "Keys cmp : " << keysCmp << endl;
                outFile << "Registers copy : " << regCpy << endl;
                break;
            }
            case 3:
            {
                int keysCmp, regCpy;
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                //Invoke selection quicksort
                int m = atoi(argv[5]);
                quicksort::quicksortSelection(array, N, m, &keysCmp, &regCpy);

                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0){
                    cerr << "Getrusage failed\n";
                }
                utime = (double) resources.ru_utime.tv_sec
                + 1.e-6 * (double) resources.ru_utime.tv_usec;

                stime = (double) resources.ru_stime.tv_sec
                + 1.e-6 * (double) resources.ru_stime.tv_usec;

                total_time = utime+stime;
                outFile << "Total time selection quicksort with N=" 
                << N << "and m="<< m <<": " << total_time <<endl;
                outFile << "Keys cmp : " << keysCmp << endl;
                outFile << "Registers copy : " << regCpy << endl;
                break;
            }
            
            case 4:
            {
                int keysCmp, regCpy;
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                //Invoke iterative quicksort
                quicksort::quisortIterative(array, N, &keysCmp, &regCpy);

                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0){
                    cerr << "Getrusage failed\n";
                }
                utime = (double) resources.ru_utime.tv_sec
                + 1.e-6 * (double) resources.ru_utime.tv_usec;

                stime = (double) resources.ru_stime.tv_sec
                + 1.e-6 * (double) resources.ru_stime.tv_usec;

                total_time = utime+stime;
                outFile << "Total time iterative quicksort with N=" 
                << N << ": " << total_time <<endl;
                outFile << "Keys cmp : " << keysCmp << endl;
                outFile << "Registers copy : " << regCpy << endl;
                break;
            }
            case 5:
            {
                int keysCmp, regCpy;
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                //Invoke smart stack quicksort
                quicksort::quisortSmartStack(array, N, &keysCmp, &regCpy);
                
                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0){
                    cerr << "Getrusage failed\n";
                }
                utime = (double) resources.ru_utime.tv_sec
                + 1.e-6 * (double) resources.ru_utime.tv_usec;

                stime = (double) resources.ru_stime.tv_sec
                + 1.e-6 * (double) resources.ru_stime.tv_usec;

                total_time = utime+stime;
                outFile << "Total time smartstack quicksort with N=" 
                << N << ": " << total_time <<endl;
                outFile << "Keys cmp : " << keysCmp << endl;
                outFile << "Registers copy : " << regCpy << endl;
                break;
            }    
        }
        cout << "Experiment with N=" << N << " completed\n";
        delete array;
    }
    cout << "All experiments completed\n";
    outFile.close();
    inFile.close();
    return 0;
}