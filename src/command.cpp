// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#include "command.h"

// Default constructor
Command::Command(){
    cmd = NULL;
}

// Main constructor
Command::Command(std::vector<std::string> input){
    // We prepare an array of cstrings to pass to execvp
    // Plus an extra for the null terminated string
    cmd = new char* [input.size()+1];

    // Iterate through the vector and copy the strings 
    for (unsigned int i = 0; i < input.size(); i++){
        cmd[i] = (char*) input.at(i).c_str(); // Ugly but need to cast
        cmd[i] = new char[input.at(i).size()+1];
	    std::strncpy(cmd[i], input.at(i).c_str(), input.at(i).size()+1);
    }
    cmd[input.size()] = NULL;

}

// Destructor
Command::~Command(){
    if (cmd){
        // Delete the children first
        //for (int i = 0; cmd[i] != NULL; i++) {
            //delete cmd[i];
        //}
        // Now deallocate the parent
        delete [] cmd;
    }
}

// We are a leaf. We have no children.
Base * Command::get_left(){
    return NULL;
}

// We are a leaf. We have no children.
Base * Command::get_right(){
    return NULL;
}

// Since we have no children we do nothing
void Command::set_left(Base* left){
    
}

// Since we have no children we do nothing
void Command::set_right(Base* right){
    
}

// Always returns true. We are a leaf.
bool Command::isLeaf(){
    return true;
}

// Returns the contents of cmd
std::string Command::to_string(){
    std::string temp;
    for (unsigned int i = 0 ; cmd[i] != NULL; i++){
        temp += std::string(cmd[i]) + " ";
    }
    return temp;
}

// Returns a vector of the contents
std::vector<std::string> Command::to_vector(){
    std::vector<std::string> v;
    for (unsigned int i = 0 ; cmd[i] != NULL; i++){
        std::string temp(std::string(cmd[i]));
        v.push_back(temp);
    }
    return v;
}

// We print out our data.
void Command::print(){
    for (unsigned int i = 0; cmd[i] != NULL; i++){
        std::cout << cmd[i] << " ";
    }
    std::cout << std::endl;
}
