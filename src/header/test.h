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

    pid_t testchild;
    int status;

    testchild = fork();
    if(testchild < 0 ){
        perror("Error: no child created");

    }

    else if(testchild != 0){
        waitpid(testchild,&status,0);
    }

    else{
    std::vector<std::string> n, m;
    n.push_back(std::string("ls"));
    n.push_back(std::string("-l"));
    m.push_back(std::string("eco"));
    m.push_back(std::string("hello"));
    Base* ls = new Command(m);
    Base* rs = new Command(n);
    Base* sc = new Semicolon_Connector(ls,rs);
    
    status = sc->execute();
    }

    std::cout<< "Commands succeded? " << status << std::endl;
    return status;
    }
};
#endif // TEST_H
