// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef BASE_H
#define BASE_H

#include <vector>
#include <string>

class Base {
    public:

    // Virtual destructor to avoid memory leaks when
    // derived classes call destructor
    virtual ~Base(){};

    // Pure virtual functions:
    
    /* Accessor functions */
    
    // Returns the left child
    virtual Base * get_left() = 0;
    
    // Returns the right child
    virtual Base * get_right() = 0;
    
    // Returns whether this is a leaf
    virtual bool isLeaf() = 0;
    
    // Prints its contents
    virtual void print() = 0;
    
    // Returns its contents as a string
    virtual std::string to_string() = 0;
    
    // Returns its contents as a vector
    virtual std::vector<std::string> to_vector() = 0;
    
    /* Mutator functions */
    
    // Sets the left child
    virtual void set_left(Base * left) = 0;
    
    // Sets the right child
    virtual void set_right(Base * right) = 0;
    
    // Executes a command returns the success status as an int
    virtual int execute() = 0;
};

#endif // BASE_H

