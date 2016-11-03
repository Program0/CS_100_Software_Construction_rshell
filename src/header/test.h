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
#include "command.h"
#include "or_connector.h"
#include "and_connector.h"
#include "semicolon_connector.h"
#include "tree.h"

class Test {
public:
    int testCommand() {
    int status;

    std::vector<std::string> m;
    m.push_back(std::string("ls"));
    m.push_back(std::string("-l"));
    
    std::vector<std::string> con;
    con.push_back(std::string("&&"));
    std::vector<std::string> n;
    n.push_back(std::string("echo"));
    n.push_back(std::string("command 2"));
    
    /*
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

    std::cout << "Test and of and and or connectors " << std::endl;
    Base* and1 = new And_Connector(an, orC);
    and1->execute();
    std::cout << "Test or of and semicolong and or connectors " << std::endl;
    Base* or2 = new Or_Connector(sc,orC);
    or2->execute();
    std::cout << "Test semicolon of and and or connectors " << std::endl;
    Base* sm = new Semicolon_Connector(and1,or2);
    sm->execute();
    
    std::cout<< "Commands succeded? if 0 yes: " << status << std::endl;
    */
    status = 69;
    // Testing the tree class
    std::vector<std::vector<std::string> > vIn;
    vIn.push_back(m);
    //vIn.push_back(n);
    Tree t;
    t.build(vIn);
    t.execute();

    return status;
    }
};
#endif // TEST_H
