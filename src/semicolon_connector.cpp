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
    int left = 0;
    std::cout << "Executing left child: " << std::endl;
    left = leftChild->execute();
    wait(NULL);
    // For debugging only
    if(left == -1){
       std::cout << "left system call failed"<< std::endl;
    }
    std::cout << "Executing right child: " << std::endl;
    int right = rightChild->execute();
    return right;
}
