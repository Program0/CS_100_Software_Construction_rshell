#ifndef COMMAND_H
#define COMMAND_H

// System libraries
#include <iostream>
#include <string>
#include <unistd.h> // For calling fork() and running commands as child

#include "base.h"

class Command : public Base {
    private:
        std::string name; //stores command and parameters
                         //as one string to pass to system
    public:

        Command(std::string n);
        int execute();
};
#endif
