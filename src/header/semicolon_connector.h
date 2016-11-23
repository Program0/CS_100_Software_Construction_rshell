//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Emmulates the behavior of the binary ; operator in the 
*  Bourne Again Shell.
*  class. 
*/

#ifndef SEMICOLON_CONNECTOR_H
#define SEMICOLON_CONNECTOR_H

#include "base.h"
#include "connector_b.h"

class Semicolon_Connector : public Connector_B {
public:
    
    // Main constructor
    Semicolon_Connector(Base* left, Base *right);
    
    // Destructor
    virtual ~Semicolon_Connector();
    
    // Prints the contents to the command line.
    void print();
    
   // Returns its contents as a string
    std::string to_string();
    
    // Returns its contents as a vector
    std::vector<std::string> to_vector();
    
    /* 
    *  Overrides Base execute. Returns a value > 0 if the right 
    *  child command successfuly executed, returns -1 if an exit 
    *  command was executed, or returns 0 if the right child  
    *  executedsuccessfully. If return value is > 0 then value   
    *  is the pid number of the right child execute() function.
    */

    int execute();
};

#endif