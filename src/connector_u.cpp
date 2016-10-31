#include "connector_u.h"

Connector_U::Connector_U(Base *childCommand): child(childCommand)
{

}

Connector_U::~Connector_U(){
    if(child!=NULL){
        delete child;
        child = NULL;
    }
}

// Stub
int Connector_U::execute(){
    return 0;
}
