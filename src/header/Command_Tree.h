// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

/* 
 * File:   TreeComposite.h
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
#include "system_call.h" // Concrete leaf class
#include "exit_command.h" // Concrete leaf class
#include "test_command.h" //Concrete leaf class
#include "and_connector.h" // Concrete composite class
#include "or_connector.h" // Concrete composite class// 
#include "semicolon_connector.h" // Concrete composite class

class Command_Tree{

private:
    // Helper function to build the tree
    void build(std::vector<std::vector<std::string> > input);
    
protected:
    Base * root;
    
public:
    /* Constructors and Destructors */
    Command_Tree();
    Command_Tree(std::vector<std::vector<std::string> > input);
    
    virtual ~Command_Tree();
    
    // Returns the root of the tree
    Base * get_root(){
        return root;        
    }
    
    // Gets the left subtree
    Base * get_left(){
        return root->get_left();
    }
    
    // Gets the right subtree
    Base *get_right(){
        return root->get_right();
    }
    
    // Sets the left subtree
    void set_left(Base * left){
        root->set_left(left);
    }
    
    // Sets the right subtree
    void set_right(Base * right){
        root->set_right(right);
    }
    
    // Executes the commands in the tree.
    int execute(){
        return root->execute();    
    }
};

#endif	/* COMMAND_TREE_H */

