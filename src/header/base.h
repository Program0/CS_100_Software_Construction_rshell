//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // For forking a process
#include <sys/types.h> // For making parent process wait
#include <sys/wait.h> // For making parent process wait
#include <stdio.h> // For using perror() and catching errors if sys call failed
#include <cstdlib> // Basic c functions
#include <errno.h> // For outputting error after system call

class Base {
    public:

    // Virtual destructor to avoid memory leaks when
    // derived classes call destructor
    virtual ~Base(){};

    // Pure virtual functions:
    virtual int execute() = 0;

};
#endif
