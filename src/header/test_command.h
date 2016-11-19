// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H

#include "command.h"

// Issues the test command.
class Test_Command: public Command {

public:

    // Main constructor
    Test_Command(std::vector<std::string > input);
    
    // Tests whether a file exists or tests the passed expression
    int execute();
};

#endif // TEST_COMMAND_H
