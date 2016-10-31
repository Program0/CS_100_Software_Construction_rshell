#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <cstdlib>


class Base {
    public:

    // Virtual destructor to avoid memory leaks when
    // derived classes call destructor
    virtual ~Base(){};

    // Pure virtual functions:
    virtual int execute() = 0;

};
#endif
