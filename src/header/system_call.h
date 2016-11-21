// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef SYSTEM_CALL_H
#define SYSTEM_CALL_H

// User libraries
#include "command.h"

// Makes system calls.
class System_Call : public Command {
public:

    // Default constructor
    System_Call() : Command(){};
    
    // Main constructor
    System_Call(std::vector<std::string> input);
    
    // Copy constructor
    System_Call(const System_Call &obj);
    
    // Assignment operator
    System_Call & operator=(const System_Call &obj);
    
    virtual ~System_Call();

    /*
    *  Makes system calls by forking and calling execvp 
    *  to execute the system calls stored in the array.
    */
    int execute();
};

#endif // SYSTEM_CALL_H
