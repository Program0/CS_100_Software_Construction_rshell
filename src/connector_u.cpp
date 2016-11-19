//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177

/*
*  For future implementation of unary connectors
*/

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


// Returns left child
Base * Connector_U::get_left(){
    return child;
}

// Returns right child
Base * Connector_U::get_right(){
    return NULL;
}

// Stub
void Connector_U::print(){

}

// Stub
int Connector_U::execute(){
    return 0;
}


