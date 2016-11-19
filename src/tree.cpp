
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
// works from right to left so that it works even when there is no parenthesis
Base* Tree::build(std::vector< std::vector<std::string> > vIn) {
	if (vIn.size() == 1) {
		if (vIn.at(0).at(0) == "Test" || vIn.at(0).at(0) == "[") //if the base single left-most command, return it
			return new Test_Command(vIn.at(0));
		return new System_Call(vIn.at(0));
	}
	Base *left = NULL, *right = NULL;
	int i = vIn.size() - 1; //start from the right and go leftwards
	while (i > 0 && vIn.at(i).at(0) != "&&" && vIn.at(i).at(0) != "||" && vIn.at(i).at(0) != ";") { //keep going left until a connector is found
		--i;
	}
	std::vector< std::vector<std::string> >::const_iterator first; //these are the boundaries of the sub vector
	std::vector< std::vector<std::string> >::const_iterator last;
	if (vIn.at(i).at(0) == ")") {
		std::stringstream convert;
		int j; //j will be the index of the corresponding left parenthesis
		convert << vIn.at(i).at(1); //we get this index from the second element of the ")" vector
		convert >> j;
		first = vIn.begin() + (j + 1);
		last = vIn.begin() + i;
		std::vector< std::vector<std::string> > subV1(first, last); //create the subvector
		right = build(subV1); set the subvector as right
		i = j - 1; //check the next element to the left
	}
	if (right == NULL) { //if the right child did not have parenthesis, make a simple command/test_command
	if (vIn.at(0).at(0) == "Test" || vIn.at(0).at(0) == "[")
			return new Test_Command(vIn.at(0));
		return new System_Call(vIn.at(0));
	}
	first = vIn.begin(); //get the rest of the stuff on the left of the connector into the left child which will be
	last = vIn.begin() + (i -1);		//properly constructed using recursive calls
	std::vector< std::vector<std::string> > subV2(first, last); //create the subvector
	left = build(subV2); //set subvector as left child
	if (vIn.at(i).at(0) == "&&") //decide which connector to use with left and right
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

