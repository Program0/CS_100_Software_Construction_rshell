// Marlo Zeroth marlo.zeroth@email.ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef TREE_H
#define TREE_H

// System libraries
#include <vector>
#include <string>
#include <cstdlib>

// User Libraries
#include "base.h" // Root - used to polymorphically and recursively call connector or command execute()
#include "command.h" // Leaf - performs system calls
#include "and_connector.h" // Node - connects leaves
#include "or_connector.h" // Node - connects leaves
#include "semicolon_connector.h" // Node - connects leaves
#include "exit_command.h" // Leaf - performs exit command

class Tree {
private:
    Base* root;

    // TODO Implement a copy constructor and assigment operator
    std::vector<std::vector<std::string> > commands;

public:
    /* Constructors and Destructor */

    // Default constructor
    Tree(): root(NULL);

    // Copy constructor 
    Tree(const Tree &tree);

    // Destructor - Recursively deallocates
    ~Tree();

    // Assignment operator
    Tree& operator= (const Tree& tree);

    // Builds the command tree based on parsed user input
    void build(std::vector<std::vector<std::string> > vIn);

    // Returns whether the tree is empty
    boolean isEmpty();

    // Clears the tree of all system calls
    void clear();

    // Executes the stored system calls
    int execute();

};

#endif // TREE_H
