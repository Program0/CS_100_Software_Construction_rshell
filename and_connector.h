#ifndef AND_CONNECTOR_H
#define AND_CONNECTOR_H

#include "base.h"
#include "connector_b.h"

class And_Connector : public Connector_B {
    public:
        And_Connector(Base* left, Base* right);
        int execute();
};
#endif
