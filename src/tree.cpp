// User Libraries
#include "tree.h"

/* Constructors and Destructor */

// Default constructor
Tree::Tree () {
    root = NULL;
}

// Copy constructor
Tree::Tree (const Tree &tree) {
    // If we are not empty clear then rebuild
    if (root != NULL)
        this->clear ();
    this->build (tree.commands);
    this->commands = tree.commands;
}

// Destructor
Tree::~Tree () {
    if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Assignment operator
Tree & Tree::operator= (const Tree& tree) {

    // If we are not empty clear then rebuild
    if (root != NULL)
        this->clear ();

    // Now we rebuild with the passed tree commands
    this->build (tree.commands);
    this->commands = tree.commands;
    return *this;
}

// Returns whether the tree is empty
bool Tree::isEmpty () {

    if (root == NULL)
        return true;

    return false;
}

// Builds the tree by calling the recursive build function
void Tree::build (std::vector< std::vector<std::string> > vIn) {
    this->root = recursiveBuild (vIn);
}

// Recursively builds the tree based on the Parsed commands vector vIn
Base* Tree::recursiveBuild (std::vector< std::vector<std::string> > vIn) {
    if (vIn.size () == 1) { //base case, if the left-most Command is reached, return it as the left-most leaf
        return new Command (vIn.at (0));
    }
    while (vIn.at (vIn.size () - 1).at (0) == ")" && vIn.at (vIn.size () - 1).at (1) == "0") { //delete unnesessary parenths
        vIn.erase (vIn.begin ());
        vIn.erase (vIn.begin () + (vIn.size () - 1));
    }
    Base *left = NULL, *right = NULL;
    int i = (vIn.size () - 1); //the recursive tree will be build from right to left
    while (i > 0 && (vIn.at (i).at (0) != "&&" && vIn.at (i).at (0) != "||" && //search for the right-most connector
            vIn.at (i).at (0) != ";" && vIn.at (i).at (0) != ")")) {
        --i;
    }
    if (vIn.at (i).at (0) == ")") {
        std::istringstream ss; //string to int of the parenthesis' left pair's index location in vIn
        ss.str (vIn.at (i).at (1));
        int pair;
        ss >> pair;
        std::vector< std::vector<std::string> >::const_iterator start = vIn.begin () + pair + 1; //set subVector start
        std::vector< std::vector<std::string> >::const_iterator end = vIn.begin () + i; //set subVector end not including found parenths
        //recursive call within the parentheses on the right of current command
        std::vector< std::vector<std::string> > subV (start, end);
        right = recursiveBuild (subV);
        if ((pair - 1) >= 0)
            i = pair - 1; //move the index to the next connector to the left of these parentheses
    }
    if (vIn.at (i).at (0) == "&&" || vIn.at (i).at (0) == "||" || vIn.at (i).at (0) == ";") {
        if (right == NULL) { //if there were no parenthesis on the right
            right = new Command (vIn.at (i + 1));
        }
        std::vector< std::vector<std::string> >::const_iterator start = vIn.begin (); //set subVector start
        std::vector< std::vector<std::string> >::const_iterator end = vIn.begin () + i; //set subVector of everthing to the left
        //recursive call within the parentheses on the right of current command
        std::vector< std::vector<std::string> > subV (start, end);
        left = recursiveBuild (subV);
        if (vIn.at (i).at (0) == "&&")
            return new And_Connector (left, right);
        if (vIn.at (i).at (0) == "||")
            return new Or_Connector (left, right);
        if (vIn.at (i).at (0) == ";")
            return new Semicolon_Connector (left, right);
    }
    std::vector<std::string> dummy; //in case any loop hole gets here, so execute doesn't crash
    dummy.push_back ("Error: bad build");
    return new Command (dummy);
}

// Empty the tree
void Tree::clear () {
    if (root) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
        this->commands.clear (); // We clear all commands
    }
}

// Executes the tree commands
int Tree::execute () {
    return root->execute ();
}
