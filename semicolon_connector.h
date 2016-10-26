#ifndef SEMICOLON_CONNECTOR_H
#define SEMICOLON_CONNECTOR_H
#include "base.h"
#include "connector_u.h"

class Semicolon_Connector :: public Base {
    public:
        Semicolon_Connector(Base* child);
        execute();
};
#endif