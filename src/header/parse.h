//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef PARSE
#define PARSE
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <cstdlib>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

class Parse {
    private:
        std::string input;

    public:
        Parse();
        void setInput(std::string input);           //to be set by user during runtime
        int parse(std::vector< std::vector<std::string> > &vOut);  //returns success/failure int
        std::string trim(std::string str);
	bool checkParenthesis(const std::string &str, std::map<int, int> &m);
        bool badInput(std::string str, int &i, char connector);
};
#endif
