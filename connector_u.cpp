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

Connector_U::execute(){

}
