
#include "rshell.h"

void RShell::execute(int argc, char* argv[]) {

    Tree *commandTree = new Tree(); // Holds and executes commands
    Parse *parser = new Parse(); // Parses user input
    std::vector< std::vector<std::string> > v; // Used to parse user input
    std::string input; // String used to parse command line and use input    

    // If we are getting arguments from the command line
    // we process here
    if (argc > 1) {
        // Get the arguments and create a string        
        std::string passedArguments;
        for (int i = 1; i < argc; i++) {
            passedArguments += std::string(argv[i]);
        }

        std::cout << "$ ";
        parser->setInput(passedArguments);
        int result = parser->parse(v);
        if (result == 0) {
            commandTree->build(v);
            commandTree->execute();
            commandTree->clear();
            v.clear();
        }
    }
}

void RShell::execute() {
    Tree *commandTree = new Tree(); // Holds and executes commands
    Parse *parser = new Parse(); // Parses user input
    std::vector< std::vector<std::string> > v; // Used to parse user input
    std::string input; // String used to parse command line and use input    

    // If it is user input
    int noExit = 0;
    do {
        std::cout << "$ ";
        std::cin.sync();
        std::getline(std::cin, input);
        parser->setInput(input);
        int result = parser->parse(v);
        if (result == 0) {
            commandTree->build(v);
            noExit = commandTree->execute();
            commandTree->clear();
            v.clear();
        }
    } while (noExit >= 0);

}
