#include "tree.h"

Tree::Tree() {
    root = NULL;
}

Tree::Tree(Base* root) {
    this->root = root;
}

void Tree::setRoot(Base* root) {
    this->root = root;
}

boolean Tree::isEmpty() {
    if (root == NULL) return true;
    return false;
}

int Tree::execute(){
    return root->execute();
}
