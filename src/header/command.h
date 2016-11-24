//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#ifndef COMMAND_H
#define COMMAND_H

// System libraries
#include <stdexcept>
#include <iostream> // For printing to the command line
#include <cstring> // For dealing with c-strings
#include <iostream> // For printing to command line
#include <cstdlib> // Basic c functions
#include <stdlib.h> // For MACRO use
#include <cstddef> // For NULL
#include <unistd.h> // For calling fork() and running commands as child
#include <sys/types.h> // For making a process wait until child finishes
#include <sys/wait.h> // For waitpid function
#include <stdio.h> // For using perror() and catching errors if sys call failed
#include <errno.h> // For outputting error after system call
#include <fcntl.h> // For testing a pipe between child and parent process
#include <sysexits.h> // For testing exit status of process
#include <sys/stat.h> // For the stat function used in test commands
#include <sys/param.h>//for accessing environment variables
#include <time.h>
#include <limits.h> // For the realpath() function and PATHMAX macro
#include <dirent.h> // For getting a directory stream


// User libraries
#include "base.h"

// Stores commands in null terminated array. The command to execute is 
// stored at index 0 and the parameters are stored subsequent elements 
// of the array. 

class Command : public Base {
private:
    /* Member variables */ 
    
    // Stores command file at index 0, flags at index 1,
    // and parameters are stored in subsequent indeces.
    char ** cmd; // Null terminated array.
    pid_t pid; // Process ID of the command.
    int exit_status; // Stores the errno of the command after execution.
    // Stores the size of the Null terminated array, 
    // not include the NULL.
    unsigned int size; 
    
    /* Utility functions */
    
    // Functions that execute built in commands. Note, this will
    // grow as we add built-in commands.
    int exit_command();
    int test_command();
    int system_call();
    int cd_command();

public:

    // Main constructor
    Command(std::vector<std::string> input);

    // Destructor
    virtual ~Command();

    // Overridden functions.
    
    /* For use in a command tree */
    
    // Returns NULL. 
    virtual Base * get_left();
    virtual Base * get_right();
    
    // Does nothing.
    virtual void set_left(Base * left);
    virtual void set_right(Base * right);
    
    // Always returns true. Commands are leafs in a command tree.
    virtual bool isLeaf();
    
    /* Accessor functions */
    
    // Prints the command and parameters.
    virtual void print();
    
    // Returns a string of the command and parameters.
    virtual std::string to_string();
    
    // Returns a vector with the command and parameters.
    virtual std::vector<std::string> to_vector();

    // Overrides Base execute function.
    virtual int execute();
};

#endif //COMMAND_H

