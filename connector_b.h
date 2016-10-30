#ifndef CONNECTOR_B_H
#define CONNECTOR_B_H

#include "base.h"

class Connector_B : public Base
{
protected:
    Base *leftChild;
    Base *rightChild;

public:

    // Main contructor
    Connector_B(Base *left, Base *right);
    virtual ~Connector_B();

    // Executes the commands stored in the left and right child
    int execute();
};

#endif // CONNECTOR_B_H
