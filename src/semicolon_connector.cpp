#include "semicolon_connector.h"

Semicolon_Connector::Semicolon_Connector(Base* left, Base *right):
    Connector_B(left, right){
	
}

Semicolon_Connector::~Semicolon_Connector(){
    if(leftChild!=NULL){
        delete leftChild;
        leftChild = NULL;
    }
    if(rightChild!=NULL){
        delete rightChild;
        rightChild = NULL;
    }
}
        
int Semicolon_Connector::execute() {
    int result = 0;
    return result;
}
