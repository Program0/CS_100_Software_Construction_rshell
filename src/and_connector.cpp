//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

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
    int left = -1; // Status of left child process
    int right= -1; // Status of right child process

    if(leftChild!=NULL)
        left = leftChild->execute();

    // We only execute if the first process succeeded
    if(rightChild!=NULL && left > -1)
        right = rightChild->execute();
    
    // We are only concerned with what happens if both execute
    if(left >-1 && right > -1) 
       return 1;
    else 
       return -1;
}
