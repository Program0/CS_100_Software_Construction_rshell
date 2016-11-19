//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef BASE_H
#define BASE_H

#include <cstddef>

class Base {
    public:

    // Virtual destructor to avoid memory leaks when
    // derived classes call destructor
    virtual ~Base(){};

    // Pure virtual functions:
    
    virtual void print() = 0;
    
    // Executes a command returns the success status as an int
    virtual int execute() = 0;
};

#endif // BASE_H
