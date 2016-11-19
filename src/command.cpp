// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#include "command.h"

// Default constructor
Command::Command(){
    cmd = NULL;
}

// Main constructor
Command::Command(std::vector<std::string> input){
    // We prepare an array of cstrings to pass to execvp
    // Plus an extra for the null terminated string
    cmd = new char* [input.size()+1];

    // Contents of vector
    // Iterate through the vector and copy the strings 
    for (unsigned int i = 0; i < input.size(); i++){
        cmd[i] = (char*) input.at(i).c_str(); // Ugly but need to cast
    }
    cmd[input.size()] = NULL;

}

// Destructor
Command::~Command(){
    if (cmd != NULL){
        // Delete the children first
        //for (int i = 0; cmd[i] != NULL; i++) {
            //delete cmd[i];
        //}
        // Now deallocate the parent
        delete [] cmd;
    }
}

void Command::print(){

}

