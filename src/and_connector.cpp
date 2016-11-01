#include "connector_b.h"
#include "and_connector.h"

And_Connector::And_Connector(Base* left, Base* right) : Connector_B(left, right) {

}

And_Connector::~And_Connector(){
    if(leftChild!=NULL){
        delete leftChild;
        leftChild = NULL;
    }
    if(rightChild!=NULL){
        delete rightChild;
        rightChild = NULL;
    }
}
        
int And_Connector::execute() {
    if (leftChild->execute() == -1)
        return -1;
    return rightChild->execute();
}
