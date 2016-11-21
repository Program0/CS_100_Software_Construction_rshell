//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177

/*
*  For future implementation of unary connectors
*/

#include "connector_u.h"

Connector_U::~Connector_U(){
    if(child){
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

// Sets the left child
void Connector_U::set_left(Base* left){
    child = left;
}

// Sets the right child
void Connector_U::set_right(Base* right){
    child = NULL;
}

// Always returns false. This is a connector
bool Connector_U::isLeaf(){
    return false;
}
