#ifndef OR_CONNECTOR_H
#define OR_CONNECTOR_H

#include "base.h"

class Or_Connector : public ConnectorB
{
public:
    Or_Connector(Base *left, Base *right);
    ~Or_Connector();

    // Executes the commands
    int execute();
};

#endif // OR_CONNECTOR_H
