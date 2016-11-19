//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "and_connector.h"

// Main constructor. Initialize with parent constructor.
And_Connector::And_Connector(Base* left, Base* right) : Connector_B(left, right) {

}

// Virtual destructor calls the Connector_B class destructor.
And_Connector::~And_Connector(){

}

// We assume by default that if a command executes it returns 0 and
// if it fails it returns something greater than 0. If an exit command 
// was executed a return value of -1 is received. If both commands 
// executed successfully then the and_connector returns 0 and if
// either failed to execute we return the error number of the left
// child command. 
int And_Connector::execute() {
    int left = -1; // Status of left child process
    int right= -1; // Status of right child process

    if (leftChild != NULL){
        // Execute left child
        left = leftChild->execute();
        
        // If command passed was exit we return
        if (left == -1)
            return left;
    }
    
    // We only execute if the first process succeeded
    if (rightChild != NULL && left == 0){  
        // We execute the right child
        right = rightChild->execute();
        
        // If the command entered was exit we return 
        if (right == -1)
            return right;
    }
    
    // We return 0 only if both execute. Otherwise, we return
    // the error number of the child command that failed.
    if (left == 0 && right == 0) 
       return 0;
    else if (left > 0)
       return left;
    else
        return right;
}
