//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177

#ifndef COMMAND_H
#define COMMAND_H

// System libraries
#include <string>
#include <vector>

// User libraries
#include "base.h"

class Command : public Base {
private:
    //stores command file at cmd[0] and parameters after that
    std::vector<std::string>cmd; // Null terminated vector

public:

    // Main constructor
    Command(std::vector<std::string> input);

    // Overriden functions
    int execute();
};
#endif
