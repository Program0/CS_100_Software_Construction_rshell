//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "test_command.h"

Test_Command::Test_Command(std::vector<std::string> input) : Command(input) {

}

// Issues the exit program program
int Test_Command::execute() {

    size_t size = PATH_MAX + 1;
    int status = 1; // Return value after execution
    std::cout << "In test command path: " << cmd[2] << std::endl;
    char *buffer1 = new char[PATH_MAX+1]; /* not sure about the "+ 1" */
    char *buffer2 = new char[PATH_MAX+1]; /* not sure about the "+ 1" */
    char *resolvedPath = realpath(cmd[2], buffer1);
    char *currentDir = getcwd(buffer2, size);
    if (resolvedPath) {
        std::cout << cmd[2] << " source is at " << resolvedPath << std::endl;

        
    } else {
        perror("Error: ");
    }
    std::cout << "current directory: " << currentDir << std::endl;
    struct stat sb;
        
        // Now we test whether this is a file, directory or otherwise
        if (stat(cmd[2], &sb) == -1) {
            status = 1;
            //perror("stat"); // Outputs an error to the command line
        }
        else{
            if ( (!std::strcmp(cmd[1], "-e")) && ((S_ISREG(sb.st_mode) == 1) 
                || (S_ISDIR(sb.st_mode) == 1)) ){
                status = 0;    
            }
            else if ( !std::strcmp(cmd[1], "-f") && S_ISREG(sb.st_mode) == 1){
                status = 0;
                std::cout << "Flag is: " << cmd[1] << std::endl;
            }
            else if ( !std::strcmp(cmd[1], "-d") && S_ISDIR(sb.st_mode) == 1){
                status = 0;
                std::cout << "It is a directory" << std::endl;
            }

            //S_ISDIR(sb.st_mode) 
        } 
    delete buffer1;
    delete buffer2;    
    // We output the success of the test function
    if (status == 0){
        std::cout << "(True)" << std::endl;
    }
    else{
        std::cout << "(False)" << std::endl;
    }
 
    return status;
}

