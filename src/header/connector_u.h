//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of an unary operator in the 
*  Bourne Again Shell. Subclasses to implement the 
*  behaviour have not been implemented.
*/

#ifndef CONNECTOR_U_H
#define CONNECTOR_U_H

#include "base.h"

// Defines the unary connector class.
class Connector_U : public Base {
protected:
    Base *child;

public:
    // Main constructor
    Connector_U(Base *childCommand);

    // Destructor
   virtual ~Connector_U();
   
    // Accesors functions
    Base * get_left();
    Base * get_right();
    
    void print();
    
    // Overrides Base's execute function
    int execute() = 0;

    //returns whether the current node is a leaf
    bool isLeaf();
};

#endif // CONNECTOR_U_H
