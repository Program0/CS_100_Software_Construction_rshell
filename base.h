#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base {
    public:

    // Virtual destructor to avoid memory leaks when
    // derived classes call destructor
    virtual ~Base(){};

    // Pure virtual functions:
    virtual int execute() = 0;

};
#endif
