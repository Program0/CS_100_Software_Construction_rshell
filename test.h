#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "base.h"
#include "command.h"
#include "or_connector.h"
#include "and_connector.h"


class Test {
public:
    int testCommand() {
    Command* ls = new Command("ls -l");
    int status = ls->execute();
    std::cout<< "Command ls succeded? "<< status << std::endl;
    return status;
    }
};
#endif // TEST_H
