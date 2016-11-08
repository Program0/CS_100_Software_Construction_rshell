//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of the binary || operator in the 
*  Bourne Again Shell.
*  class. 
*/

#ifndef OR_CONNECTOR_H
#define OR_CONNECTOR_H

#include "connector_b.h"
#include "base.h"

class Or_Connector : public Connector_B {
public:

    // Main constructor
    Or_Connector(Base *left, Base *right);
    
    // Destructor
    virtual ~Or_Connector();

    // Executes the commands
    int execute();
};

#endif // OR_CONNECTOR_H

