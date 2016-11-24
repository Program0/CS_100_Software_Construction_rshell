//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "semicolon_connector.h"

// Main constructor
Semicolon_Connector::Semicolon_Connector(Base* left, Base *right):
    Connector_B(left, right){
	
}

// Default constructor. Calls Connector_B class destructor.
Semicolon_Connector::~Semicolon_Connector(){

}

// Only print the connector. Let the leaves print their data.
void Semicolon_Connector::print(){
    std::cout << ";" << std::endl;
}

std::string Semicolon_Connector::to_string(){
    std::string temp(";");
    return temp;
}

std::vector<std::string> Semicolon_Connector::to_vector(){
    std::string temp(";");
    std::vector<std::string> v;
    v.push_back(temp);
    return v;
}

// We assume by default that if a command executes it returns 0 and
// if it fails it returns something greater than 0. If an exit command 
// was executed a return value of -1 is received. If right child command
// executed successfully then the semicolon_connector returns the return
// value of the right child execute() function.        
int Semicolon_Connector::execute() {
    // Assume exit command from the start
    int left = -1; // Status of left child process
    int right = -1 ; // Status of right child process

    // We execute the left child
    if (leftChild != NULL){
        left = leftChild->execute();
        
        // If the exit command was received, we exit
        if (left == -1)
            return left;
    }

    // Execute the next command if there is one
    if (rightChild != NULL)
        right = rightChild->execute();
    
    // We return the result of executing the right child command.
    return right;
}
