//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "exit_command.h"

// Default constructor
Exit_Command::Exit_Command() : Command(){

}

// Parent constructor. We let the parent handle memory allocation
Exit_Command::Exit_Command(std::vector<std::string> input) : Command(input){

}

// Copy constructor
Exit_Command::Exit_Command(const Exit_Command& obj) {

    if (obj.cmd) {
        // Clear our contents
        delete [] this->cmd;

        // Get the size of obj->cmd
        unsigned int size;
        for (size = 0; obj.cmd[size] != NULL; size++) {

        }

        // Now we copy the contents of obj
        // We prepare an array of cstrings to pass to execvp
        // Plus an extra for the null terminated string
        this->cmd = new char* [size + 1];

        // Iterate through the vector and copy the strings 
        for (unsigned int i = 0; i < size; i++) {
            this->cmd[i] = new char [strlen(obj.cmd[i]) + 1];
            std::strncpy(this->cmd[i], obj.cmd[i], strlen(obj.cmd[i]) + 1);
        }
        this->cmd[size] = NULL;
    }

}

// Destructor. Parent takes care of deallocating memory.
Exit_Command::~Exit_Command(){
    
}

// Assignment operator
Exit_Command & Exit_Command::operator=(const Exit_Command& obj) {
    if (obj.cmd) {
        // Clear our contents
        delete [] this->cmd;

        // Get the size of obj->cmd
        unsigned int size;
        for (size = 0; obj.cmd[size] != NULL; size++) {

        }

        // Now we copy the contents of obj
        // We prepare an array of cstrings to pass to execvp
        // Plus an extra for the null terminated string
        this->cmd = new char* [size + 1];

        // Iterate through the vector and copy the strings 
        for (unsigned int i = 0; i < size; i++) {
            this->cmd[i] = new char [strlen(obj.cmd[i]) + 1];
            std::strncpy(this->cmd[i], obj.cmd[i], strlen(obj.cmd[i]) + 1);
        }
        this->cmd[size] = NULL;
    }
    return *this;
}

// Issues the exit program program
int Exit_Command::execute() {
    // We return -1 to signify exit.
    return -1;
}
