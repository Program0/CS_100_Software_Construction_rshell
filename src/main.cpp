//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// System libraries
#include <vector>

// User libraries
#include "tree.h"
#include "parser.h"


int main(int argc, char *argv[])
{

    Tree commandTree = new Tree();
    Parse parser = new Parse();
    std::vector< std::vector<std::string> > v;
    std::string input;
    while(true){
        std::cout << "$ ";
        cin >> input;
        p.setInput(input);
        int result = p.parse(v);
        if (result > 0) {
            commandTree.build(v);
            t.execute();
            t.clear();
        }

    }
    /*
    Test mytest;
    mytest.testCommand();
    return 0;
    */
}

