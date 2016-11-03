//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#include "base.h"
#include "command.h"
#include "or_connector.h"
#include "and_connector.h"
#include "semicolon_connector.h"

class Test {
public:
    int testCommand() {
    int status;

    std::vector<std::string> m;
    m.push_back(std::string("lm"));
    m.push_back(std::string("-l"));
    std::vector<std::string> n;
    n.push_back(std::string("echo"));
    n.push_back(std::string("command 2"));
    Base* ls = new Command(m);
    Base* rs = new Command(n);
    Base* sc = new Semicolon_Connector(ls,rs);
    Base* an = new And_Connector(ls,rs);
    Base* orC = new Or_Connector(ls,rs);

    std::cout << "semicolon: " << std::endl;
    status = sc->execute();
    std::cout << "Or: " << std::endl;
    status = orC->execute();
    std::cout << "And: " << std::endl;
    status = an->execute();
    std::cout<< "Commands succeded? if 0 yes: " << status << std::endl;
    return status;
    }
};
#endif // TEST_H
