//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#ifndef COMMAND_H
#define COMMAND_H

// System libraries
#include <iostream>
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

// User libraries
#include "base.h"

// Stores commands in null terminated array. The command to execute is 
// stored at index 0 and the parameters are stored subsequent elements 
// of the array. 
class Command : public Base {
protected:
    // Stores command file at index 0, flags at index 1,
    // and parameters are stored in subsequent indeces
    char **cmd; // Null terminated array

public:

    // Default constructor
    Command();

    // Main constructor
    Command(std::vector<std::string> input);
    
    // Destructor
    virtual ~Command();
    
    // Overridden functions. Derived classes do
    // not have to implement these.
    virtual Base * get_left();
    virtual Base * get_right();
    virtual void set_left(Base * left);
    virtual void set_right(Base * right);
    virtual void print();    
    virtual bool isLeaf();
    virtual std::string to_string();
    virtual std::vector<std::string> to_vector();

    // Overrides Base execute function. Derived classes need
    // to implement this.
    virtual int execute() = 0;
};

#endif //COMMAND_H
