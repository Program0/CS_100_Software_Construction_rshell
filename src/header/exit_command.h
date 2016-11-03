#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include "base.h"

class Exit_Command: public Base {

public:

    // Empty constructor
    Exit_Command();

    // Issues the exit program program
    int execute();  

};
#endif

