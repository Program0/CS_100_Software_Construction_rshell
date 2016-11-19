// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of the binary && operator in the 
*  Bourne Again Shell.
*  class. 
*/

#ifndef AND_CONNECTOR_H
#define AND_CONNECTOR_H

#include "base.h"
#include "connector_b.h"

// Defines the && connector.
class And_Connector : public Connector_B {

public:
    
    // Main constructor
    And_Connector(Base* left, Base* right);
    
    // Destructor
    virtual ~And_Connector();

    /* 
    *  Overriden execute. Returns 0 if both commands
    *  successfuly executed, returns -1 if an exit command
    *  was executed, or returns > 0 indicating failure. If the 
    *  return value is > 0 then value is the pid number of the 
    *  left child execute() function.
    */
    int execute();
        
};

#endif // AND_CONNECTOR_H