#include "command.h"
#include <iostream>

Command::Command(string n) {
    name = n;
}

Comand::execute() {
    //TODO perform system call

    //if(system returns error)
    //return -1;

    cout << "command name: " << name << endl;
    return 0; //manual change this for testing connectors
}