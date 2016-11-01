#ifndef TREE_H
#define TREE_H

#include <vector>
#include "base.h"

class Tree : public Base
{
protected:
    Base* root;

public:
    Tree(Base* root);
    int execute();

};

#endif // TREE_H
