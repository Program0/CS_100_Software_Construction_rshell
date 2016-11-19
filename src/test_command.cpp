// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#include "test_command.h"

Test_Command::Test_Command(std::vector<std::string> input) : Command(input) {

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

