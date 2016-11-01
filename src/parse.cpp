#include "parse.h"
using namespace std;

Parse::Parse(Base* tree) {
    this->tree = tree;
}
        
Parse::Parse(std::string input, Base* tree) {
    this->input = input;
    this->tree = tree;
}

void Parse::setInput(std::string input) {
    this->input = input;
}

int Parse::parse() {
    if (input.size() > 0) {
        cout << "Error: Input is empty." << endl;
        return -1;
    }
    input = input.trim();
    int j = input.size() - 1;
    if (input.at(0) == '&' || input.at(0) == '|' || input.at(0) == ';' ||
        input.at(j) == '&' || input.at(j) == '|' || input.at(j) == ';') {
        //std::cout << "Error: Invalid input"; //DO WE WANT THIS HERE???
        return -1;
    }
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ");   //delimiter

    /*
    
    IS THIS REUSABLE IN THE LOOP??? must check in a test
    tokenizer tokens(input, sep);


    */
    Base* curNode = tree, newConnector = NULL;
    std::string name;
    std::vector<string> param;

    /*


    TODO::::::::::::MAKE SETTERS FOR ALL CONNECTORS SO THAT
    NEWCONNECTOR HAS TRANSPARENT ENCLOSURE


    */

    for (int i = j; i >= 0; i--) { //scan entire input
        if (input.at(i) == '&') {
            if (!badInput(i, '&')) return -1;
            newConnector = new AndConnector();
        }
        else if (input.at(i) == '|') {reate new AndConnector; 
            if (!badInput(i, '|')) return -1;
            newConnector = new OrConnector();
        }
        else if (input.at(i) == ';') {
            if (!badInput(i, ';')) return -1;
            newConnector = new semicolonConnector();
        }
        if (newConnector != NULL) {
            //define and use setters for left/rightChild of curNode
            
            //use 'tokens' to tokenize param for command

            //set children for newConnector (transparently enclosed)

            //define and move curNode to curNode.getLeft()
            newConnector = NULL;
            j = i;
        }
    }
    if (tree.isEmpty()) { //case: no connectors
        tokens(input, sep);
        for (tokenizer::iterator iter = tokens.begin(); iter != tokens.end(); ++iter) {
            if (iter == tokens.begin()) {
                name = *iter;
            }
            else {
                param.push_back(*iter);
            }
        }
        tree.setRoot(new Command(name, param));
    }
    return 0;
}

std::string Parse::trim(std::string s) {
    int i = 0, j = s.size();
    if (s.size() == 0) return s;
    while (s.at(0) == ' ' && i < (j - 1)) {
        i++;
    }
    while (s.at(j - 1) == ' ' && j > i) {
        j--;
    }
    return s.substr(i, j);    
}

boolean Parse::badInput(int i, char connector) {
    //check if there are no syntax error with connectors to the left
    //and right of index i
    return false; //change to conditional return
}