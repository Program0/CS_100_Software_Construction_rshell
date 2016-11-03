#include "tree.h"

Tree::Tree() {
    root = NULL;
}

// Copies a tree
Tree::Tree(const Tree &tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
}

// Assignment operator
Tree & Tree::operator= (const Tree& tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
}

// Returns whether the tree is empty
boolean Tree::isEmpty() {
    if (root == NULL) return true;
    return false;
}

void Tree::build(std::vector<std::vector<std::string>> vIn) {
    if ((vIn.size() % 2) != 0) {
        root = new Command(vIn.at(0));
        if (vIn.size() > 1) {
            int i = 1;
            while (i < (vIn.size() - 1)) {
                if (vIn.at(i).at(0) == "&") {
                   root = new And_Connector(root, new Command(vIn.at(i + 1)));
                }
                else if (vIn.at(i).at(0) == "|") {
                    root = new Or_Connector(root, new Command(vIn.at(i + 1)));
                }
                else if (vIn.at(i).at(0) == ";") {
                    root = new Semicolon_Connector(root, new Command(vIn.at(i + 1)));
                }
                i += 2;
            }
        }
    }
}

// Empty the tree
void Tree::clear(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Executes the tree commands
int Tree::execute(){
    return root->execute();
}
