
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
    std::cout << "building, vIn size: " << vIn.size() << std::endl;    
    if ((vIn.size() % 2) != 0) {
        if (vIn.at(0).at(0) == "exit") {
            std::cout<< "Creating exit command" << std::endl;
            root = new Exit_Command();
        }
        else {
            std::cout << " creating first command" <<std::endl;
            root = new Command(vIn.at(0));
            // Print the command
            std::cout << "Vector of vector of string commands size: " << vIn.size() << std::endl;
            std::cout << "vector of string commands size: " << vIn.at(0).size() << std::endl;
            for (unsigned int i = 0; i < vIn.at(0).size(); i++) {
                std::cout << "Vector.at(" << i << ")" << vIn.at(0).at(i) << std::endl;
            }
        }
        if (vIn.size() > 1) {
            int i = 1;
            Base* command;
            while (i < (((int) vIn.size()) - 1)) {
                std::cout<< " i is: " << i << " and i + 1 is " << (i+1) << std::endl;
                if (vIn.at(i + 1).at(0) == "exit") {
                    std::cout<< "Creating exit command at i = " << i << std::endl;
                    command = new Exit_Command();
                }
                else {
                    std::cout << "Creating regular command " << vIn.at(i+1).at(0) << " at i + 1 = " << i+1 << std::endl;
                    command = new Command(vIn.at(i + 1));
                    std::cout << "Added command " << vIn.at(i+1).at(0) << std::endl;
                }
    
                if (vIn.at(i).at(0) == "&") {
                    std::cout << "Creating && connector at i = " << i << " " << vIn.at(i).at(0) << std::endl;
                    root = new And_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == "|") {
                   std::cout << "Creating || connector at i = " << i << " " << vIn.at(i).at(0) << std::endl;
                   root = new Or_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == ";") {
                    std::cout << "Creating ; connector at i = " << i << " " << vIn.at(i).at(0) << std::endl;
                    root = new Semicolon_Connector(root, command);
                }
                i += 2;
            }
        }
    }
std::cout<< "Finished creating tree " << std::endl;
}

// Empty the tree
void Tree::clear(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
        this->commands.clear(); // We clear all commands
    }
}

// Executes the tree commands
int Tree::execute(){
    return root->execute();
}

/* Utility functions */

// Recursively executes the commands stored in the tree in post order
// and ends recursion if any of the commands is the exit command.
int Tree::executeCommand(Base * node, int status){

    // If it is a single command in the tree we execute and return
    if (this->commands.size() == 1 && node->isLeaf()) {
        return node->execute();
    }
    
    // If an exit return statement was in the command tree
    // we exit the recursion
    if (status == -1) {
        return status;
    }
    // If it is a connector we continue the recursion until we
    // finish executing all the commands.
    if (!node->isLeaf()) {
        status = executeCommand(node, node->execute());
        return status;
    }
    else{
        status = node->execute();
        return status;
    }
}

