//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// System libraries
#include <vector>

// User libraries
#include "tree.h"
#include "parse.h"
#include "test.h"


int main(int argc, char *argv[])
{
    
    // Note we need to clear the vector and 
    // the string passed to parser if we issue
    // new commands.    
    Tree *commandTree = new Tree();
    Parse *parser = new Parse();
    std::vector< std::vector<std::string> > v;
    std::string input;
    int noExit = 0;
    while( noExit >=0 ){
        std::cout << "$ ";
        std::cin.sync();
        std::getline(std::cin,input);
        parser->setInput(input);
        int result = parser->parse(v);
        if (result == 0) {
            commandTree->build(v);
            noExit = commandTree->execute();
            commandTree->clear();
            v.clear();
        }
    }
    /*
    
    
    Test mytest;
    mytest.testCommand();
    return 0;
    */
}

