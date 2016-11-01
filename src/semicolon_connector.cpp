#include "semicolon_connector.h"

// Main constructor
Semicolon_Connector::Semicolon_Connector(Base* left, Base *right):
    Connector_B(left, right){
	
}

// Default constructor
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
    // Assume failure from the start
    int right = -1 ; // Status of right child process

    if(leftChild!=NULL)
        leftChild->execute();

    // Execute the next command if there is one
    if(rightChild!=NULL)
        right = rightChild->execute();
    
    // We are only concerned with what happens with the next command
    return right;
}
