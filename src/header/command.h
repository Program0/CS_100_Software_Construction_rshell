#ifndef COMMAND_H
#define COMMAND_H

// System libraries
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // For calling fork() and running commands as child
#include <sys/types.h> // For making a process wait until child finishes
#include <sys/wait.h> // For wait
#include <stdio.h> // For perror

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
