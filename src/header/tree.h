// Marlo Zeroth marlo.zeroth@email.ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef TREE_H
#define TREE_H

// System libraries
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

// User Libraries
#include "base.h" // Root - used to polymorphically and recursively call connector or command execute()
#include "command_tree.h" // For creating subtrees when there are parenthesis
#include "command.h" // Leaf - performs commands
#include "and_connector.h"
#include "or_connector.h"
#include "semicolon_connector.h"

class Tree {
private:
    Base* root;

    // Stores the 
    std::vector<std::vector<std::string> > commands;

public:
    /* Constructors and Destructor */

    // Default constructor
    Tree();

    // Copy constructor 
    Tree(const Tree &tree);

    // Destructor - Recursively deallocates
    ~Tree();

    // Assignment operator
    Tree& operator=(const Tree& tree);

    // Builds the tree by calling the recursive build function
    void build(std::vector<std::vector<std::string> > vIn);

    // Recursively builds the tree based on the Parsed commands vector vIn
    Base* recursiveBuild(std::vector< std::vector<std::string> > vIn);

    // Returns whether the tree is empty
    bool isEmpty();

    // Clears the tree of all system calls
    void clear();

    // Executes the stored command calls
    int execute();

};

#endif // TREE_H
