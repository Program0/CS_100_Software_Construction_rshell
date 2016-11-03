//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177

#ifndef AND_CONNECTOR_H
#define AND_CONNECTOR_H

#include "base.h"
#include "connector_b.h"

class And_Connector : public Connector_B {
    public:
        And_Connector(Base* left, Base* right);
        virtual ~And_Connector();
        int execute();
};
#endif
