//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

/*
*  Decorator class to suppress execution of commands in a command tree 
*  that emmulates the behavior of Bourne Again Shell.
*  class. 
*/

#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

// System libraries
#include <stdio.h>
#include <stdlib.h>

// User libraries
#include "command.h"

// Issues the exit command. 
class Exit_Command: public Command {

public:

    // Default constructor
    Exit_Command();
    
    // Main constructor
    Exit_Command(std::vector<std::string> input);
    
    // Always returns -1 as flag to exit the rshell
    int execute();
};

#endif // EXIT_COMMAND_H

