//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// User libraries
#include "parse.h"
        
Parse::Parse() {
}

void Parse::setInput(std::string input) {
	//sets the input string to be processed
    this->input.clear();
    this->input = input;
}

int Parse::parse(std::vector< std::vector<std::string> > &vOut) {
	vOut.clear(); //clears the last vector to receive new output
	//check if empty input
	if (input.size() == 0) {
		std::cout << "Error: Input is empty." << std::endl;
		return -1;
	}
	input = trim(input);
	int j = input.size() - 1;
	//check for leading/trailing connector syntax errors
	if (input.at(0) == '&' || input.at(0) == '|' || input.at(0) == ';' ||
		input.at(j) == '&' || input.at(j) == '|' || input.at(j) == ';') {
		std::cout << "Error: Invalid input" << std::endl; //DO WE WANT THIS HERE???
		return -1;
	}
	//set up string tokenizer
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(" ");   //delimiter
	std::vector<std::string> tempV;
	std::string tempS;
	int firstCmd;
	for (int i = 0; i < (int)input.size(); ++i) { //scan entire input
		//only does work at the connectors
		if (input.at(i) == '&' || input.at(i) == '|' || input.at(i) == ';') {
			firstCmd = i;
			if (badInput(input, i, input.at(i))) return -1;   //checks for bad connector syntax

			if (vOut.empty()) {     //if first connector, must make initial left-most command leaf
				tokenizer firstTk(input.substr(0, firstCmd), sep);
				std::vector<std::string> u;
				//fill the command vector with command and parameters
				for (tokenizer::iterator itr = firstTk.begin(); itr != firstTk.end(); ++itr) {
					u.push_back(*itr);
				}
				vOut.push_back(u);
			}

			j = i;
			while (input.at(j) != '&' || input.at(j) != '|' ||      //find the end of the next command
				input.at(j) != ';' || j <= ((int)input.size() - 1)) {
				++j;
			}
			tokenizer tokens(input.substr((i + 1), (j - i + 1)), sep);
			std::vector<std::string> v;
			for (tokenizer::iterator iter = tokens.begin(); iter != tokens.end(); ++iter) {
				v.push_back(*iter);
			}
			//create a vector entry for the connector
			tempV.clear();
			tempS = "";
			tempS += input.at(i);
			//if connector is || or &&, add the second symbol for readability
			if (input.at(i) != ';')
				tempS += input.at(i);
			//add connector vector to output
			tempV.push_back(tempS);
			vOut.push_back(tempV);
			//add command vector to output
			vOut.push_back(v);
		}
	}
	if (vOut.empty()) { //case: no connectors
		tokenizer firstTk(input.substr(0, input.size()), sep);
		std::vector<std::string> v;
		for (tokenizer::iterator itr = firstTk.begin(); itr != firstTk.end(); ++itr) {
			v.push_back(*itr);
		}
		vOut.push_back(v);
	}
	std::cout << std::endl;
	for (int index = 0; index < vOut.size(); index++) {
		std::cout << vOut.at(index) << std::endl;
	}
	std::cout << std::endl;
    return 0;
}

std::string Parse::trim(std::string str) {
	if (s.size() == 0) return s;
    int j = 0;
	bool inQuote = false;
	//find the last relevant character in the string to get rid of any comments
    while (j < (int) (str.size()) && !inQuote && str.at(j) != '#') {
		//flags string-literal status "inQuote" to
		//make sure that the comment is not in a string-literal
		if (str.at(j) == '"') {
			if (inQuote) inQuote = false;
			else inQuote = true;
		}
        ++j;
    }
    std::string s = str.substr(0, j);    //cut off irrelevant end of string
    int i = 0; //left side edge
    j = s.size(); //right side edge
	//ignore any spaces
    while (s.at(i) == ' ' && i < (j - 1)) {
        i++;
    }
    while (s.at(j - 1) == ' ' && j > i) {
        j--;
    }
	//cuts off spaces on the ends of the string
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
