//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef CONNECTOR_U_H
#define CONNECTOR_U_H

#include "base.h"

class Connector_U : public Base {
protected:
    Base *child;

public:
    // Main constructor
    Connector_U(Base *childCommand);

    // Destructor
   virtual ~Connector_U();

    int execute();
};

#endif // CONNECTOR_U_H
