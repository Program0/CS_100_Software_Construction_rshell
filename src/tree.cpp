
// User Libraries
#include "tree.h"

/* Constructors and Destructor */

// Default constructor
Tree::Tree() {
    root = NULL;
}

// Copy constructor
Tree::Tree(const Tree &tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
}

// Destructor
Tree::~Tree(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Assignment operator
Tree & Tree::operator= (const Tree& tree){

    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    
    // Now we rebuild with the passed tree commands
    this->build(tree.commands);
    this->commands = tree.commands;
    return *this;
}

void Tree::setRoot(Base* r) {
	root = r;
}

// Returns whether the tree is empty
bool Tree::isEmpty() {

    if (root == NULL) 
        return true;
        
    return false;
}

// Builds the tree based on the passed commands in vector vIn
Base* Tree::build(std::vector< std::vector<std::string> > vIn) {
	if (vIn.size() == 1) {
		if (vIn.at(0).at(0) == "Test" || vIn.at(0).at(0) == "[")
			return new Test_Command(vIn.at(0));
		return new System_Call(vIn.at(0));
	}
	Base *left = NULL, *right = NULL;
	int i = vIn.size() - 1;
	while (i > 0 && vIn.at(i).at(0) != "&&" && vIn.at(i).at(0) != "||" && vIn.at(i).at(0) != ";") {
		--i;
	}
	std::vector< std::vector<std::string> >::const_iterator first;
	std::vector< std::vector<std::string> >::const_iterator last;
	if (vIn.at(i).at(0) == ")") {
		std::stringstream convert;
		int j; //j will be the number of the corresponding left parenth
		convert << vIn.at(i).at(1);
		convert >> j;
		first = vIn.begin() + (j + 1);
		last = vIn.begin() + i;
		std::vector< std::vector<std::string> > subV1(first, last);
		right = build(subV1);
		i = j - 1; //check the next element to the left
	}
	if (right == NULL) { //make the right child the unparenthesized command
		if (vIn.at(0).at(0) == "Test" || vIn.at(0).at(0) == "[")
			return new Test_Command(vIn.at(0));
		return new System_Call(vIn.at(0));
	}
	first = vIn.begin();
	last = vIn.begin() + (i -1);
	std::vector< std::vector<std::string> > subV2(first, last);
	left = build(subV2);
	if (vIn.at(i).at(0) == "&&")
		return new And_Connector(left, right);
	if (vIn.at(i).at(0) == "||")
		return new Or_Connector(left, right);
	if (vIn.at(i).at(0) == ";")
		return new Semicolon_Connector(left, right);
	
	std::vector<std::string> defaultV; //if bad input, make empty command
	defaultV.push_back("");
	return new Command(defaultV);
}

// Empty the tree
void Tree::clear(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
        this->commands.clear(); // We clear all commands
    }
}

// Executes the tree commands
int Tree::execute(){
    return root->execute();
}

/* Utility functions */

// Recursively executes the commands stored in the tree in post order
// and ends recursion if any of the commands is the exit command.
int Tree::executeCommand(Base * node, int status){

    // If it is a single command in the tree we execute and return
    if (this->commands.size() == 1 && node->isLeaf()) {
        return node->execute();
    }
    
    // If an exit return statement was in the command tree
    // we exit the recursion
    if (status == -1) {
        return status;
    }
    // If it is a connector we continue the recursion until we
    // finish executing all the commands.
    if (!node->isLeaf()) {
        status = executeCommand(node, node->execute());
        return status;
    }
    else{
        status = node->execute();
        return status;
    }
}

