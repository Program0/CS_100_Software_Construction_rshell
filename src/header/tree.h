#ifndef TREE_H
#define TREE_H

#include <vector>
#inclue <stdlib>
#include "base.h"

class Tree : public Base
{
protected:
    Base* root;

public:
    Tree();
    Tree(Base* root);
    void setRoot(Base* root);
    boolean isEmpty();
    int execute();

};

#endif // TREE_H