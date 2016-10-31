#ifndef OR_CONNECTOR_H
#define OR_CONNECTOR_H

#include "connector_b.h"
#include "base.h"

class Or_Connector : public Connector_B {
public:
    Or_Connector(Base *left, Base *right);
    virtual ~Or_Connector();

    // Executes the commands
    int execute();
};

#endif // OR_CONNECTOR_H
