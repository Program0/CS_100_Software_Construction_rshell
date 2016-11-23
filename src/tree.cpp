// User Libraries
#include "tree.h"

/* Constructors and Destructor */

// Default constructor
Tree::Tree() {
    root = NULL;
}

// Copy constructor
Tree::Tree(const Tree &tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
}

// Destructor
Tree::~Tree(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Assignment operator
Tree & Tree::operator= (const Tree& tree){

    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    
    // Now we rebuild with the passed tree commands
    this->build(tree.commands);
    this->commands = tree.commands;
    return *this;
}

// Returns whether the tree is empty
bool Tree::isEmpty() {

    if (root == NULL) 
        return true;
        
    return false;
}

// Builds the tree based on the passed commands in vector vIn
void Tree::build(std::vector< std::vector<std::string> > vIn) {
    this->commands = vIn;   
    if ((vIn.size() % 2) != 0) {
        // We create the first command
        root = new Command(vIn.at(0));        
        
        if (vIn.size() > 1) {
            int i = 1;
            Base* command;
            while (i < (((int) vIn.size()) - 1)) { 
                // The next command is always after the connector
                command = new Command(vIn.at(i + 1));
                
                // Now we create the connectors
                if (vIn.at(i).at(0) == "&&") {
                    root = new And_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == "||") {
                   root = new Or_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == ";") {
                    root = new Semicolon_Connector(root, command);
                }
                i += 2;
            }
        }
    }
}

// Empty the tree
void Tree::clear(){
  if (root) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
        this->commands.clear(); // We clear all commands
    }
}

// Executes the tree commands
int Tree::execute(){
    return root->execute();
}

