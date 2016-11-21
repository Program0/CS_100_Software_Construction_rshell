//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of an unary operator in the 
*  Bourne Again Shell. Subclasses to implement the 
*  behaviour have not been implemented.
*/

#ifndef CONNECTOR_U_H
#define CONNECTOR_U_H

// System Libraries
#include <iostream> // For printing to command line
#include <cstddef> // For NULL

// User Libraries
#include "base.h"

// Defines the unary connector class.
class Connector_U : public Base {
protected:
    Base *child;

public:    
    // Default constructor
    Connector_U() : child(NULL){};
    
    // Main constructor
    Connector_U(Base *command) : child(command){};

    // Destructor
   virtual ~Connector_U();
   
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
    // Returns its contents as a string
    virtual std::string to_string() = 0;
    
    // Returns its contents as a vector
    virtual std::vector<std::string> to_vector() = 0;

    /* Mutator functions */
    // Executes the commands stored in the left and right.
    virtual int execute() = 0;
    
};

#endif // CONNECTOR_U_H
