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
