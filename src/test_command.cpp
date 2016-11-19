//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "test_command.h"

Test_Command::Test_Command(std::vector<std::string> input) : Command(input) {

}

// Issues the exit program program
int Test_Command::execute() {

    std::cout << "In test command " << std::endl;
    char *buffer = new char[PATH_MAX+1]; /* not sure about the "+ 1" */
    char *resolvedPath = realpath("main.cpp", buffer);
    if (resolvedPath) {
        std::cout << "main.cpp" << " source is at " << buffer << std::endl;
    } else {
        perror("realpath");
    }
    delete buffer;
    /*
    struct stat sb;
    if (stat(cmd[2], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }   
    */ 
    return 1;
}

