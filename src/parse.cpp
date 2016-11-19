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
	input = trim(input);
	if (input.size() == 0) {
		std::cout << "Error: Input is empty." << std::endl;
		return -1;
	}
	int j = input.size() - 1;
	//check for leading/trailing connector syntax enp p rrors
	if (input.at(0) == '&' || input.at(0) == '|' || input.at(0) == ';' ||
		input.at(j) == '&' || input.at(j) == '|' || input.at(j) == ';') {
		std::cout << "Error: Invalid input" << std::endl;
		return -1;
	}
        std::map<int, int> parenthesisMap; //check iuf parenthesis and brackets are properly grouped
        if (!checkParenthesis(input, parenthesisMap)) { //also update hashmap to where '('s matching ')' is
		std::cout << "Error: Invalid Input" << std::endl;
		return -1;
        }
	//syntax tests passed.
	//set up string tokenizer delimiter
	const char *delim = " ";
	std::vector<std::string> tempV;
	std::string tempS;
	int firstCmd;
	for (int i = 0; i < (int)input.size(); ++i) { //scan entire input
		//only does work at the connectors
		if (input.at(i) == '&' || input.at(i) == '|' || input.at(i) == ';') {
			firstCmd = i;
			bool bad = badInput(input, i, input.at(i));
			if (bad) return -1;   //checks for bad connector syntax

			if (vOut.empty()) {     //if first connector, must make initial left-most command leaf
				std::vector<std::string> u;
				//fill the command vector with command and parameters
				char *strCopy = strdup(input.substr(0, firstCmd).c_str());
				char *token = strtok(strCopy, delim);
       				while (token != NULL) {
               				 u.push_back(std::string(token));
               				 token = strtok(NULL, delim);
       				}
				free(strCopy); 
				vOut.push_back(u);
			}

            j = i;
            while (j < ((int) input.size()) && input.at(j) != '&'      //find the end of the next command
                   && input.at(j) != '|' && input.at(j) != ';') {
                ++j;
            }
            std::vector<std::string> v;
	    char *strCopy = strdup(input.substr(i, (j - i)).c_str());
            char *token = strtok(strCopy, delim);
            while (token != NULL) {
                v.push_back(std::string(token));
            	token = strtok(NULL, delim);
            }
            free(strCopy);
            tempV.clear();
            tempS = "";
            tempS += input.at(i - 1); //save connector char as tree flag
	    if (input.at(i - 1) != ';')
	        tempS += input.at(i - 1); //double char flag if necessary
            tempV.push_back(tempS); //store flag into a vector<string>
            vOut.push_back(tempV); //store vector of next command
            vOut.push_back(v);
        }
    }
    if (vOut.empty()) { //case: no connectors
        std::vector<std::string> v;
	char *strCopy = strdup(input.substr(0, input.size()).c_str());
        char *token = strtok(strCopy, delim);
        while (token != NULL) {
               	v.push_back(std::string(token));
       		token = strtok(NULL, delim);
        }
        free(strCopy);
        vOut.push_back(v);
    }
    return 0;
}

std::string Parse::trim(std::string str) {
    if (str.size() == 0) return str;
    if (str.at(0) == '#') return ""; //check for all comments
    if (str.size() == 1 && str.at(0) == ' ') return "";
    int j = 0;
    bool inQuote = false;
    //find the last relevant character in the string to get rid of any comments
    while (j < (int) (str.size())) {
	if (!inQuote && str.substr(j, 2) == " #") break;
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

bool Parse::checkParenthesis(const std::string &str, std::map<int, int> &m) {
    std::stack<std::string> parenthesis;
    std::stack<std::string> brackets;
    for (int i = str.size() -1; i >= 0; --i) {
        if (str.at(i) == ')') {
            std::ostringstream ss;
	    ss << i;
            parenthesis.push(ss.str());
        }
        if (str.at(i) == ']') {
            std::ostringstream ss;
            ss << i;
            brackets.push(ss.str());
        }
        if (str.at(i) == '(') {
            if (parenthesis.size() == 0) 
                return false;
            std::stringstream ss;
            ss << parenthesis.top();
            int index;
            ss >> index;
            m.insert(std::make_pair(i, index));
            parenthesis.pop();
        }
        if (str.at(i) == '[') {
            if (brackets.size() == 0)
                return false;
            brackets.pop();
        }
    }
    if (parenthesis.size() > 0 || brackets.size() > 0)
        return false;
    else
        return true;
}

bool Parse::badInput(std::string str, int &i, char connector) {
    if (i >= (int) input.size()) 
	return true; //double check that the connect is not at the end of the string
    int j = i + 1;
    if (str.at(j) == '&' || str.at(j) == '|' || str.at(j) == ';') {
        if (str.at(j) != connector)
            return true; //bad input if there are different adjacent connectors
        if (j < (int) input.size() && (str.at(j + 1) == '&' || str.at(j + 1) == '|' || str.at(j + 1) == ';'))
            return true; //bad input if there is a third connectors
    }
    if (str.at(j) == connector) //set i to the beginning of the next command
        i = j;
    while (i < (int) input.size() && (input.at(i) == '&' || input.at(i) == '|' || input.at(i) == ';')) {
	++i;
    }
    return false; //change to conditional return
}
