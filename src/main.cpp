//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// System libraries
#include <vector>

// User libraries
#include "rshell.h"

int main(int argc, char *argv[]){
    
    RShell rshell;
    
    // If we have command line arguments we process those
    // otherwise we process with user input.    
    if(argc > 1){
        rshell.execute(argc, argv);
    }
    else{
        rshell.execute();
    }
    
return 0;
}

