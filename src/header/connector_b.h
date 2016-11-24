// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of a logical binary operator in the 
*  Bourne Again Shell. The connector class and_connector
*  or_connector, and semicolon_connector derive from this
*  class. 
*/

#ifndef CONNECTOR_B_H
#define CONNECTOR_B_H

// System Libraries
#include <iostream> // For printing to command line
#include <cstddef> // For NULL

// User Libraries
#include "base.h"

// Defines the binary connector class.
class Connector_B : public Base {
protected:
    Base *leftChild;
    Base *rightChild;

public:

    // Default constructor
    Connector_B() : leftChild(NULL), rightChild(NULL){};
    // Main contructor
    Connector_B(Base *left, Base *right);
    
    // Destructor
    virtual ~Connector_B();
          
    // Overridden functions. Child classes do 
    // not need to implement these.
    
    /* Accesor functions */
    virtual Base * get_left();
    virtual Base * get_right();
    virtual bool isLeaf();
    
    /* Mutator functions */
    
    // Sets the left child
    virtual void set_left(Base * left);    
    // Sets the right child
    virtual void set_right(Base * right);

    // Derived classes need to implement these functions.   
    
    /* Accesor functions */
    
    // Prints its contents
    virtual void print() = 0;
    
    // Returns its contents as a string
    virtual std::string to_string() = 0;
    
    // Returns its contents as a vector
    virtual std::vector<std::string> to_vector() = 0;

    /* Mutator functions */
    // Executes the commands stored in the left and right.
    virtual int execute() = 0;
    
};

#endif // CONNECTOR_B_H
