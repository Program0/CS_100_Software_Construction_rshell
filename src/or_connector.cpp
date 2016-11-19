//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "or_connector.h"

// Main constructor. Initialize with parent constructor.
Or_Connector::Or_Connector(Base *left, Base *right):Connector_B(left, right){

}

// Calls the Connector_B class destructor
// after the Or_Connector destructor is called.
Or_Connector::~Or_Connector(){

}

// We assume by default that if a command executes it returns 0 and
// if it fails it returns something greater than 0. If an exit command 
// was executed a return value of -1 is received. If both commands 
// executed successfully then the or_connector returns 0 and if
// either failed to execute we return the error number of the right
// child command. 
int Or_Connector::execute(){

    // We assume by default that command received was to exit
    int left = -1; // Status of left child process
    int right= -1; // Status of right child process
    
    if (leftChild != NULL){
        left = leftChild->execute();
        
        // Received exit command
        if (left == -1)
            return left;
    }

    // We only execute if the first one failed
    if (rightChild != NULL && left > 0){
        right = rightChild->execute();
        
        // Received exit command
        if (right == -1)
            return right;
        }
    
    // If both failed to execute, we return the error of the right
    // child command. Otherwise, we return success.
    if (left > 0 && right > 0) 
       return right;
    else 
       return 0;
}
