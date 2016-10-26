#ifndef AND_CONNECTOR_H
#define AND_CONNECTOR_H
#include "base.h"
#include "connector_b.h"

class And_Connector :: public Base {
    public:
        And_Connector(Base* left, Base* right);
        execute();
};
#endif