//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
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
