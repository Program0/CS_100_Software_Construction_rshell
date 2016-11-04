#include "tree.h"

Tree::Tree() {
    root = NULL;
}

Tree::~Tree(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Copies a tree
Tree::Tree(const Tree &tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
}

// Assignment operator
Tree & Tree::operator= (const Tree& tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
    return *this;
}

// Returns whether the tree is empty
bool Tree::isEmpty() {
    if (root == NULL) return true;
    return false;
}

void Tree::build(std::vector< std::vector<std::string> > vIn) {
//std::cout << "building, vIn size: " << vIn.size() << std::endl; 
//    int count = 0;   
/*
    // We have two cases either we have only one command or 
    // we have several commands with connectors. If we have 
    // several commands with connectors then we need to build the 
    // first connector the add subsequent connectors and a command
    // to the tree

    // First case: only one command
    if(vIn.size()==1){
        root = new Command(vIn.at(0));
    }

    // Second case we have multiple commands. Each connector is a left subtree of 
    // the next connector and the command is only added to the right subtree of the
    // next connector.
    else {
        // we build the first connector and its left and right leaves. The connector is in the middle
        Base *cmdLeft = new Command(vIn.at(0));
        Base *cmdRight = new Command(vIn.at(2));

        // We check what type of connector and allocate memory accordingly
        if(vIn.at(1).at(0)=="&&"){
            root = new And_Connector(cmdLeft,cmdRight);
        }
        
        if(vIn.at(1).at(0)=="||"){
            root = new Or_Connector(cmdLeft,cmdRight);
        }

        if(vIn.at(1).at(0)==";"){
            root = new Semicolon_Connector(cmdLeft,cmdRight);
        }

        // Now iterate through the rest of the vector and add connectors in order
        // from left to right with their commands as the right leaf

        for (int i = 3; i < vIn.size() - 1; i+=2){

            // We check whether we are getting a command or a connector
            if ( vIn.at(i).at(0)=="&&" || vIn.at(i).at(0)=="||" || vIn.at(i).at(0)==";"){
                if(vIn.at(1).at(0)=="&&"){
                    Base *rightCmd;

                    // We check for an exit command and create command accordingly
                    (vIn.at(i+1).at(0)=="exit")?
                        rightCmd = new Exit_Command() :  
                        rightCmd = new Command(vIn.at(i+1));
                    // Add the existing tree as the left subtree and the leaf as the right subtree
                    root = new And_Connector(root,rightCmd);
                }
        
                if (vIn.at(1).at(0)=="||") {
                    Base *rightCmd = new Command(vIn.at(i+1));
                    root = new Or_Connector(root,rightCmd);
                }

                if (vIn.at(1).at(0)==";") {
                    Base *rightCmd = new Command(vIn.at(i+1));
                    root = new Or_Connector(root,rightCmd);
                }
  
            }

        }

    }
*/
std::cout << "building, vIn size: " << vIn.size() << std::endl;    
        if ((vIn.size() % 2) != 0) {

        std::cout << " creating first command" <<std::endl;
        root = new Command(vIn.at(0));
        if (vIn.size() > 1) {
            int i = 1;
            Base* command;
            while (i < (((int) vIn.size()) - 1)) {
                std::cout<< " i is: " << i << " and i + 1 is " << (i+1) << std::endl;
                if (vIn.at(i + 1).at(0) == "exit") {
                    std::cout<< "Creating exit command at i = " << i << std::endl;
                    command = new Exit_Command();
                }
                else {
                    std::cout << "Creating regular command " << vIn.at(i+1).at(0) << " at i + 1 = " << i+1 << std::endl;
                    command = new Command(vIn.at(i + 1));
                    std::cout << "Added command " << vIn.at(i+1).at(0) << std::endl;
                }
                if (vIn.at(i).at(0) == "&&") {
                   std::cout << "Creating && connector at i = " << i << " " << vIn.at(i).at(0) << std::endl;
                   root = new And_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == "||") {
                   std::cout << "Creating || connector at i = " << i << " " << vIn.at(i).at(0) << std::endl;
                    root = new Or_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == ";") {
                   std::cout << "Creating ; connector at i = " << i << " " << vIn.at(i).at(0) << std::endl;
                    root = new Semicolon_Connector(root, command);
                }
                i += 2;
            }
        }
    }
std::cout<< "Finished creating tree " << std::endl;
}

// Empty the tree
void Tree::clear(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Executes the tree commands
int Tree::execute(){
    return root->execute();
}
