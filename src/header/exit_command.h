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
#include "base.h"

class Exit_Command: public Base {

public:

    // Empty constructor
    Exit_Command();

    // Issues the exit program program
    int execute();
    
    // Returns that his command is a leaf
    bool isLeaf();

};
#endif

