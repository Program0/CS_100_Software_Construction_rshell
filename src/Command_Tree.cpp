// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#include "Command_Tree.h"

// Default constructor.
Command_Tree::Command_Tree() {
    root = NULL;
}

// Main constructor. Depends on build.
Command_Tree::Command_Tree(std::vector<std::vector<std::string> > input) {
    build(input);
}

// Recursively deletes the tree nodes.
Command_Tree::~Command_Tree() {
    if (root) {
        delete root;
    }
}

// Builds the tree based on passed vector of vectors.
void Command_Tree::build(std::vector<std::vector<std::string> > input) {
    // If the vector is odd size, we know we have correct input
    if ((input.size() % 2) != 0) {
        // We build the tree assuming only command is in the vector.
        if (input.at(0).at(0) == "exit") {
            root = new Exit_Command();
        } else if (input.at(0).at(0) == "test") {
            root = new Test_Command(input.at(0));
        } else {
            root = new System_Call(input.at(0));
        }
        
        // If the size is greater than 1, we have subtrees to build.
        if (input.size() > 1) {
            // We assume a connector immediately follows the command
            // built in the previous section. Then commands will be 
            // at even indeces and connectors at odd indeces.
            unsigned int i = 1;
            
            // We iterate through the vector and build accordingly
            Base* command;
            while (i < (input.size() - 1)) {
                // We build the commands.
                if (input.at(i + 1).at(0) == "exit") {
                    command = new Exit_Command();
                }
                else if (input.at(i + 1).at(0) == "test") {
                    command = new Test_Command(input.at(i + 1));
                } 
                else {
                    command = new System_Call(input.at(i + 1));
                }
                // We build the connectors.
                if (input.at(i).at(0) == "&&") {
                    root = new And_Connector(root, command);
                } else if (input.at(i).at(0) == "||") {
                    root = new Or_Connector(root, command);
                } else if (input.at(i).at(0) == ";") {
                    root = new Semicolon_Connector(root, command);
                }
                // Go to the next connector
                i += 2;
            }
        }
    }
}
