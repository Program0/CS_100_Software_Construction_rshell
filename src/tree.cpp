
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

// Returns whether the tree is empty
bool Tree::isEmpty() {

    if (root == NULL) 
        return true;
        
    return false;
}

// Builds the tree by calling the recursive build function
void Tree::build(std::vector< std::vector<std::string> > vIn) {
	this->root = recursiveBuild(vIn);
}

// Recursively builds the tree based on the Parsed commands vector vIn
Base* Tree::recursiveBuild(std::vector< std::vector<std::string> > vIn) {
	if (vIn.size() == 1) { //base case, if the left-most Command is reached, return it as the left-most leaf
		if (vIn.at(0).at(0) == "test")
			return new Test_Command(vIn.at(0));
		else if (vIn.at(0).at(0) == "[") {
			vIn.at(0).at(0) = "test"; //reformat brackets to say "test ..."
			if (vIn.at(0).size() > 1 && vIn.at(0).at(1).at(0) 1 = '-') { //if there is no flag, set default "-e"
				std::vector<std::string>::const_iterator it = vIn.at(0).begin() + 1;
				vIn.at(0).insert(it, "-e");
			}
			if (vIn.at(0).at(size() -1) == "]")
				vIn.at(0).pop_back(); //get right of "]"
			return new Test_Command(vInt.at(0));
		}
		else
			return new Command(vIn.at(0));
	}
	Base* left = NULL, right = NULL;
	int i = (vIn.size() - 1); //the recursive tree will be build from right to left
	while (i > 0 && (vIn.at(i).at(0) != "&&" || vIn.at(i).at(0) != "||" || //search for the right-most connector
		vIn.at(i).at(0) != ";" || vIn.at(i).at(0) != ")")) {
		--i;
	}
	if (vIn.at(i).at(0) == ")") {
		ostringstream ss; //string to int of the parenthesis' left pair's index location in vIn
		ss << vIn.at(i).at(1);
		int pair;
		ss >> pair;
		std::vector< std::vector<std::string> >::const_iterator start = vIn.at(i).begin() + pair + 1; //set subVector start
		std::vector< std::vector<std::string> >::const_iterator end = vIn.at(i).begin() + i; //set subVector end not including found parenths
		//recursive call within the parentheses on the right of current command
		right = recursiveBuild(std::vector< std::vector<std::string> > subV(first, last));
		i = pair - 1; //move the index to the next connector to the left of these parentheses
	}
	if (vIn.at(i).at(0) == "&&" || vIn.at(i).at(0) == "||" || vIn.at(i).at(0) == ";") {
		if (right == NULL) { //if there were no parenthesis on the right
			if (vIn.at(i).at(0) == "test")
				right = new Test_Command(vIn.at(i));
			else if (vIn.at(i).at(0) == "[") {
				vIn.at(i).at(0) = "test"; //reformat brackets to say "test ..."
				if (vIn.at(i).size() > 1 && vIn.at(i).at(1).at(0) != '-') { //if there is no flag, set default "-e"
					std::vector<std::string>::const_iterator it = vIn.at(i).begin() + 1;
					vIn.at(0).insert(it, "-e");
				}
				if (vIn.at(0).at(size() - 1) == "]")
					vIn.at(0).pop_back(); //get right of "]"
				right = new Test_Command(vInt.at(0));
			}
			else
				right = new Command(vIn.at(0));
		}
		std::vector< std::vector<std::string> >::const_iterator start = vIn.at(i).begin(); //set subVector start
		std::vector< std::vector<std::string> >::const_iterator end = vIn.at(i).begin() + i - 1; //set subVector end not including found parenths
		//recursive call within the parentheses on the right of current command
		left = recursiveBuild(std::vector< std::vector<std::string> > subV(first, last));
		if (vIn.at(i).at(0) == "&&")
			return new And_Connector(left, right);
		if (vIn.at(i).at(0) == "||")
			return new Or_Connector(left, right);
		if (vIn.at(i).at(0) == ";")
			return new Semicolon_Connector(left, right);
	}
	std::vector<std::string> dummmy; //in case any loop hole gets here, so execute doesn't crash
	dummy.push_back("Error: bad build");
	return new Command(dummy);
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

