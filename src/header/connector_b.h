//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of a logical binary operator in the 
*  Bourne Again Shell. The connector class and_connector
*  or_connector, and semicolon_connector derive from this
*  class. 
*/

#ifndef CONNECTOR_B_H
#define CONNECTOR_B_H

#include "base.h"

class Connector_B : public Base {
protected:
    Base *leftChild;
    Base *rightChild;

public:

    // Main contructor
    Connector_B(Base *left, Base *right);
    
    // Destructor
    virtual ~Connector_B();

    // Executes the commands stored in the left and right child
    int execute();
    
    // Returns whether the connector is a leaf. Always returns false.
    bool isLeaf();
};

#endif // CONNECTOR_B_H

