
#include <iostream>

#include "command.h"


Command::Command(std::string n) {
    name = n;
}

int Command::execute() {
    //TODO perform system call

    //if(system returns error)
    //return -1;

    std::cout << "command name: " << name << std::endl;
    return 0; //manual change this for testing connectors
}
