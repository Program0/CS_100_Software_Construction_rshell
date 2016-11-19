//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef TEST_H
#define TEST_H

// System Libraries
#include <vector>
#include <string>
#include <iostream>

// User Libraries
#include "base.h"
#include "and_connector.h"
#include "or_connector.h"
#include "semicolon_connector.h"
#include "system_call.h"
#include "exit_command.h"
#include "test_command.h"
#include "tree.h"

class Test {
public:
    int testCommand() {
    int status;

    std::vector<std::string> m;
    m.push_back(std::string("lm"));
    m.push_back(std::string("-l"));
    
    std::vector<std::string> con1;
    con1.push_back(std::string("||"));

    std::vector<std::string> n;
    n.push_back(std::string("eho"));
    n.push_back(std::string("hello world"));
    
    std::vector<std::string> con2;
    con2.push_back(std::string("&&"));

    std::vector<std::string> n1;
    n1.push_back(std::string("echo"));
    n1.push_back(std::string("second connector"));

    std::vector<std::string> con3;
    con3.push_back(std::string("&&"));

    std::vector<std::string> n2;
    n2.push_back(std::string("exit"));

    std::vector<std::string> con4;
    con4.push_back(std::string(";"));

    std::vector<std::string> n3;
    n3.push_back(std::string("ls"));
    
    std::vector<std::string> n4;
    n4.push_back(std::string("test"));


    status = 69;
    // Testing the tree class
    std::vector<std::vector<std::string> > vIn;
    vIn.push_back(m);
    vIn.push_back(con1);
    vIn.push_back(n);
    vIn.push_back(con2);
    vIn.push_back(n1);
    vIn.push_back(con3);
    vIn.push_back(n2);
    vIn.push_back(con4);
    vIn.push_back(n3);
    //vIn.push_back(con4);
    //vIn.push_back(n4);

    
    Tree t;
    t.build(vIn);
    t.execute();
    
    std::cout << "concluded tests." << std::endl;
    return status;
    }
};
#endif // TEST_H
