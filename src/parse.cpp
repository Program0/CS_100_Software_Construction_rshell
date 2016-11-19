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
	//check for leading/trailing connector syntax errors
	if (input.at(0) == '&' || input.at(0) == '|' || input.at(0) == ';' ||
		input.at(j) == '&' || input.at(j) == '|' || input.at(j) == ';') {
		std::cout << "Error: Invalid input" << std::endl;
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
		if (input.at(i) == '&' || input.at(i) == '|' || input.at(i) == ';' || input.at(i) == '(' || input.at(i) == ')') {
			firstCmd = i;
			if (input.at(i) == '&' || input.at(i) == '|' || input.at(i) == ';') {
				bool bad = badInput(input, i, input.at(i));
				if (bad) return -1;   //checks for bad connector syntax
			}
			if (vOut.empty() && i > 0) {     //if first connector, must make initial left-most command leaf
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
            j = i + 1;
			while (j < ((int)input.size()) && input.at(j) != '&'      //find the end of the next command
				&& input.at(j) != '|' && input.at(j) != ';'
				&& input.at(j) != '(' && input.at(j) != ')') {
				++j;
			}
            tempV.clear(); //use temps to store current command
            tempS = "";
            tempS += input.at(i); //save connector char as tree flag
			if (input.at(i) == '&' || input.at(i) == '|')
				tempS += input.at(i); //double char flag if && or ||
            tempV.push_back(tempS); //store flag into a vector<string>
            vOut.push_back(tempV); //store vector of connector flag
			
			if (j < ((int)input.size()) && j == (i + 1)) { //only when there is a next command, store it
				std::vector<std::string> v; //vectorize the next command
				char *strCopy = strdup(input.substr(i, (j - i)).c_str());
				char *token = strtok(strCopy, delim);
				while (token != NULL) {
					v.push_back(std::string(token));
					token = strtok(NULL, delim);
				}
				free(strCopy);
				vOut.push_back(v); //store the command vector
			}
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
        vOut.push_back(v); //store the only command in the vector
    }
	if (!checkParenthesis(vOut)) { //sets flags for matching parenthesis and set pair index with the right-most parenthesis
		std::cout << "Error: Invalid Input" << std::endl;
		vOut.clear();
		return -1;
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

bool Parse::checkParenthesis(std::vector< std::vector<std::string> > &vOut) {
    std::stack<int> parenthesis; //for matching up parenthesis
    std::stack<int> brackets; //for matching up brackets
	for (int i = 0; i < (int)  vOut.size(); ++i) { //work from right to left and store left parenth's match is in vector.at(1)
		if (vOut.at(i).at(0) == "(") {
			parenthesis.push(i);
		}
        if (vOut.at(i).at(0) == "[") { //store this to be popped by its mate
            brackets.push(i);
        }
        if (vOut.at(i).at(0) == ")") {	//this is a found mate and will store the index of with the right-most parenth
			if (parenthesis.size() == 0)
				return false;
			std::ostringstream ss; //use string stream to convert from int index to string
			ss << parenthesis.top();
			vOut.at(i).push_back(ss.str());
            parenthesis.pop();
        }
        if (vOut.at(i).at(0) == "]") { //found a mate for brackets, do not store index
            if (brackets.size() == 0) //since the tree is not affected by these
                return false;
            brackets.pop();
        }
    }
    if (parenthesis.size() > 0 || brackets.size() > 0) //if there are any parentheses left, it is invalid
        return false;
    else
        return true;
}

bool Parse::badInput(std::string str, int &i, char connector) { //only for logical connectors, not parenthesis
	int j = i + 1;
	if (str.at(j) != connector)
		return true; //bad input if there are different adjacent logical connector
	
	if (j < (int)input.size() && (str.at(j + 1) == '&' || str.at(j + 1) == '|' || str.at(j + 1) == ';'))
		return true; //bad input if there is a third logical connector
	
	if (str.at(j) == connector) //set i to second contiguous connector if necessary
		i = j;
    return false; //change to conditional return
}
