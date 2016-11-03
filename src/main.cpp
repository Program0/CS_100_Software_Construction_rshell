//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// System libraries
#include <vector>

// User libraries
#include "tree.h"
#include "parse.h"


int main(int argc, char *argv[])
{

    Tree *commandTree = new Tree();
    Parse *parser = new Parse();
    std::vector< std::vector<std::string> > v;
    std::string input;
    while(true){
        std::cout << "$ ";
        std::cin >> input;
        parser->setInput(input);
        int result = parser->parse(v);
        if (result > 0) {
            commandTree->build(v);
            commandTree->execute();
            commandTree->clear();
        }

    }
    /*
    Test mytest;
    mytest.testCommand();
    return 0;
    */
}

