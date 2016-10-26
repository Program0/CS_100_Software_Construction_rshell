#ifndef CONNECTOR_U_H
#define CONNECTOR_U_H


class Connector_U : public Base
{
protected:
    Base *child;

public:
    // Main constructor
    Connector_U(Base *childCommand);

    // Destructor
    ~Connector_U();

    int execute();
};

#endif // CONNECTOR_U_H
