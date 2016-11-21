// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#include "test_command.h"

// We let the parent handle construction of its member variables.
Test_Command::Test_Command() : Command(){
    
}

// Main constructor
Test_Command::Test_Command(std::vector<std::string > input) : Command(input) {

}

// Copy constructor
Test_Command::Test_Command(const Test_Command& obj) {

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
Test_Command::~Test_Command(){
    
}

// Assignment operator
Test_Command & Test_Command::operator=(const Test_Command& obj) {
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
int Test_Command::execute() {

    //size_t size = PATH_MAX + 1;
    int status; // Return value after execution
    std::cout << "In test command path: " << cmd[2] << std::endl;
    char *buffer1 = new char[PATH_MAX+1]; /* not sure about the "+ 1" */
    //char *buffer2 = new char[PATH_MAX+1]; /* not sure about the "+ 1" */
    std::string temp("../");
    temp+= std::string(cmd[2]);

    char *resolvedPath = realpath(temp.c_str(), buffer1);
    std::cout << "Path: " << temp.c_str() << std::endl;
    //char *currentDir = getcwd(buffer2, size);
    if (resolvedPath) {
            std::cout << "Path: " << resolvedPath << std::endl;
    } else {
        perror("Error");
    }
 
    struct stat sb;
        
        // We test whether this is a file, directory or otherwise
        if (stat(cmd[2], &sb) == -1) {
            status = 1;
            //perror("stat"); // Outputs an error to the command line
        }
        else{
            // If it is either a directory or file
            if ( (!std::strcmp(cmd[1], "-e")) && ((S_ISREG(sb.st_mode) == 1) 
                || (S_ISDIR(sb.st_mode) == 1)) ){
                status = 0;    
            }// If it is a file only
            else if ( !std::strcmp(cmd[1], "-f") && S_ISREG(sb.st_mode) == 1){
                status = 0;
            }// If it is a directory only
            else if ( !std::strcmp(cmd[1], "-d") && S_ISDIR(sb.st_mode) == 1){
                status = 0;
            }
            else {
                status = 1;
            }
        } 
    delete buffer1;
    //delete buffer2;    
    // We output the success of the test function
    if (status == 0){
        std::cout << "(True)" << std::endl;
    }
    else{
        std::cout << "(False)" << std::endl;
    } 
    return status;
}

