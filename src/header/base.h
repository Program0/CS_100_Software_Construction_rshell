// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177
#ifndef BASE_H
#define BASE_H

#include <cstddef>

class Base {
    public:

    // Virtual destructor to avoid memory leaks when
    // derived classes call destructor
    virtual ~Base(){};

    // Pure virtual functions:
    virtual int execute() = 0;
    
    // Returns whether this node is a leaf or not.
    virtual bool isLeaf() = 0;

};
#endif
