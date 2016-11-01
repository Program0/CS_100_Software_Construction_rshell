#include "command.h"
#include <iostream>

Command::Command(std::string name, std::vector<std::string> param) {
    this->name = name;
    this->param = param;
}

int Command::execute() {
    //TODO perform system call

    //if (system returns error)
    //return -1;

    std::cout << "command name: " << name << std::endl;
    return 0; //manual change this for testing connectors
}
