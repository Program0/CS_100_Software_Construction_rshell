// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

/* 
 * File:   composite_tree.h
 * Author: Marlo Zeroth
 *
 * Created on November 19, 2016, 5:47 PM
 */

#ifndef COMMAND_TREE_H
#define	COMMAND_TREE_H

// System libraries
#include <vector>
#include <string>
#include <cstdlib>

// User Libraries
#include "base.h" // Abstract Base Class
#include "command.h"
#include "and_connector.h" // Concrete composite class
#include "or_connector.h" // Concrete composite class// 
#include "semicolon_connector.h" // Concrete composite class

class Command_Tree {
protected:
    Base * root;

public:

    /* Constructors and Destructors */
    Command_Tree() {
        root = NULL;
    };

    virtual ~Command_Tree() {
        if (root) {
            delete root;
        }
    };

    // Returns the root of the tree

    Base * get_root() {
        return root;
    }

    // Gets the left subtree

    Base * get_left() {
        return root->get_left();
    }

    // Gets the right subtree

    Base *get_right() {
        return root->get_right();
    }

    // Sets the left subtree

    void set_left(Base * left) {
        root->set_left(left);
    }

    // Sets the right subtree

    void set_right(Base * right) {
        root->set_right(right);
    }

    // Executes the commands in the tree.

    int execute() {
        return root->execute();
    }
};

class OpCommand : public Command_Tree {
public:

    OpCommand(std::vector<std::string> input) {
        root = new Command(input);
    }
};

class OrCommand : public Command_Tree {
public:

    OrCommand(Command_Tree * left, std::vector<std::string> input) {
        Base * command = new Command(input);
        root = new Or_Connector(left->get_root(), command);
    }
};

class AndCommand : public Command_Tree {
public:

    AndCommand(Command_Tree * left, std::vector<std::string> input) {
        Base * command = new Command(input);
        root = new And_Connector(left->get_root(), command);
    }
};

class SemiCommand : public Command_Tree {
public:

    SemiCommand(Command_Tree * left, std::vector<std::string> input) {
        Base * command = new Command(input);
        root = new Semicolon_Connector(left->get_root(), command);
    }
};

#endif	/* COMMAND_TREE_H */

