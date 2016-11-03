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

int Tree::execute(){
    return root->execute();
}
