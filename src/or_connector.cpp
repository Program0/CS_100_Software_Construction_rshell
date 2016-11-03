//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177

#include "or_connector.h"

Or_Connector::Or_Connector(Base *left, Base *right):Connector_B(left, right){

}

Or_Connector::~Or_Connector(){
    if(this->leftChild !=NULL){
        delete this->leftChild;
    }
    if(this->rightChild!=NULL){
        delete this->rightChild;
    }
}

int Or_Connector::execute(){
    int left = -1; // Status of left child process
    int right= -1; // Status of right child process

    if(leftChild!=NULL)
        left = leftChild->execute();

    // We only execute if the first one failed
    if(rightChild!=NULL && left == -1)
        right = rightChild->execute();
    
    // We are only concerned with what happens if both fail
    if(left == -1 && right == -1) 
       return -1;
    else 
       return 1;
}
