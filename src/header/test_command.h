// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H

// System libraries
#include <sys/stat.h> // For the stat function used in test commands
#include <time.h>
#include <limits.h> // For the realpath() function and PATHMAX macro
#include <dirent.h> // For getting a directory stream

// User libraries
#include "command.h"

// Issues the test command.
class Test_Command: public Command {

public:

    // Default constructor
    Test_Command();
    // Main constructor
    Test_Command(std::vector<std::string > input);
    
    // Copy constructor
    Test_Command(const Test_Command & obj);
    
    // Destructor
    virtual ~Test_Command();
    
    // Assignment operator
    Test_Command & operator=(const Test_Command & obj);
    
    // Tests whether a file exists or tests the passed expression
    int execute();
};

#endif // TEST_COMMAND_H
