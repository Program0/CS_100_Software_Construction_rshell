//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of the binary ; operator in the 
*  Bourne Again Shell.
*  class. 
*/

#ifndef SEMICOLON_CONNECTOR_H
#define SEMICOLON_CONNECTOR_H

#include "base.h"
#include "connector_b.h"

class Semicolon_Connector : public Connector_B {
public:
    
    // Main constructor
    Semicolon_Connector(Base* left, Base *right);
    
    // Destructor
    virtual ~Semicolon_Connector();
    
    // Overrides the execute in the base class
    int execute();
};
#endif

