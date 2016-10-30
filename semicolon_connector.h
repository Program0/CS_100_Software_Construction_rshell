#ifndef SEMICOLON_CONNECTOR_H
#define SEMICOLON_CONNECTOR_H

#include "base.h"
#include "connector_b.h"

class Semicolon_Connector : public Connector_B {
    public:
        Semicolon_Connector(Base* left, Base *right);
        virtual ~Semicolon_Connector();
        int execute();
};
#endif
