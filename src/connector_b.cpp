//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "connector_b.h"

// Main constructor
Connector_B::Connector_B(Base *left, Base *right)
{
    leftChild = left;
    rightChild = right;
}

// Virtual destructor calls the Base class destructor 
// after Connector_B class destructor is called
Connector_B::~Connector_B() {
    if (leftChild != NULL) {
        delete leftChild;
        leftChild = NULL;
    }
    if (rightChild != NULL) {
        delete rightChild;
        rightChild = NULL;
    }
}

// Returns left child
Base * Connector_B::get_left(){
    return leftChild;
}

// Returns right child
Base * Connector_B::get_right(){
    return rightChild;
}

// Stub
void Connector_B::print(){

}

// Overriden execute()
int Connector_B::execute(){
    return 0;
}

bool Connector_B::isLeaf() {
    return false;
}

