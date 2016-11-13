//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// User libraries
#include "parse.h"
        
Parse::Parse() {
}

void Parse::setInput(std::string input) {
    this->input.clear();
    this->input = input;
}

int Parse::parse(std::vector< std::vector<std::string> > &vOut) {
    vOut.clear();
    if (input.size() == 0) {
        std::cout << "Error: Input is empty." << std::endl;
        return -1;
    }
    input = trim(input);   //check for leading/trailing connector error
    int j = input.size() - 1;
    if (input.at(0) == '&' || input.at(0) == '|' || input.at(0) == ';' ||
        input.at(j) == '&' || input.at(j) == '|' || input.at(j) == ';') {
        std::cout << "Error: Invalid input" << std::endl; //DO WE WANT THIS HERE???
        return -1;
    }
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ");   //delimiter
    std::vector<std::string> tempV;
    std::string tempS;
    int firstCmd;
    for (int i = 0; i < (int) input.size(); ++i) { //scan entire input
            if (input.at(i) == '&' || input.at(i) == '|' || input.at(i) == ';') {
            firstCmd = i;
            if (badInput(input, i, input.at(i))) return -1;   //checks for bad connector syntax

            if (vOut.empty()) {     //if first connector, must make initial left-most command leaf
                tokenizer firstTk(input.substr(0, firstCmd), sep);
                std::vector<std::string> u;
                for (tokenizer::iterator itr = firstTk.begin(); itr != firstTk.end(); ++itr) {
                    u.push_back(*itr);
                }
                vOut.push_back(u);
            }

            j = i;
            while (input.at(j) != '&' || input.at(j) != '|' ||      //find the end of the next command
                   input.at(j) != ';' || j <= ((int) input.size() - 1)) {
                ++j;
            }
            tokenizer tokens(input.substr((i + 1), (j - i + 1)), sep);
            std::vector<std::string> v;
            for (tokenizer::iterator iter = tokens.begin(); iter != tokens.end(); ++iter) {
                v.push_back(*iter);
            }
            tempV.clear();
            tempS = "";
            tempS += input.at(i);
	    if (input.at(i) != ';')
	        tempS += input.at(i);
            tempV.push_back(tempS);
            vOut.push_back(tempV);
            vOut.push_back(v);
        }
    }
    if (vOut.empty()) { //case: no connectors
        std::cout << "string parsed: " << input.substr(0, input.size()) << std::endl;
        //tokenizer firstTk(input.substr(0, input.size()), sep); // Does not work. What if we change the substring?
        boost::tokenizer<>firstTk(input);// Works with more than one parameter
        std::vector<std::string> v;
        for (boost::tokenizer<>::iterator itr = firstTk.begin(); itr != firstTk.end(); itr++) {
            v.push_back(*itr);
            std::cout << "adding " << *itr << " to vector" << std::endl;
        }
        vOut.push_back(v);
    }
    
    for (unsigned int k = 0; k < vOut.size(); k++) {
        for (unsigned int l = 0; l < vOut.at(k).size(); l++){
            std::cout << "String saved: " << vOut.at(k).at(l) << std::endl;
        }
    }
    
    return 0;
}

std::string Parse::trim(std::string str) {
    int j = 0;
    while (j < (int) (str.size()) && str.at(j) != '#') { //maybe try with (str.size() - 1) if the last char gets cut off
        ++j;
    }
    std::string s = str.substr(0, j);    //gets rid of comments
    int i = 0;
    j = s.size();
    if (s.size() == 0) return s;
 
    while (s.at(i) == ' ' && i < (j - 1)) {
        i++;
    }
    while (s.at(j - 1) == ' ' && j > i) {
        j--;
    }
    return s.substr(i, (j - i));    
}

bool Parse::badInput(std::string str, int &i, char connector) {
    int j = i + 1;
    if (str.at(j) == '&' || str.at(j) == '|' || str.at(j) == ';') {
        if (str.at(j) != connector)
            return true; //bad input if there are different adjacent connectors
        if (str.at(j + 1) == '&' || str.at(j + 1) == '|' || str.at(j + 1) == ';')
            return true; //bad input if there is a third connectors
    }
    if (str.at(j) == connector)
        i = j;
    return false; //change to conditional return
}
