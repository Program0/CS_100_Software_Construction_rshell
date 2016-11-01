#ifndef PARSE
#define PARSE
#include "base.h"
#include "Tree.h"
#include "semicolon_connector.h"
#include "or_connector.h"
#include "and_connector.h"
#include "command.h"
#include "comment.h"
#include <iostream>
#include <string>
#include <stdlib>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

class Parse {
    private:
        std::string input = "";
        Base* tree = NULL;

    public:
        Parse(Base* tree);				//if no input yet
        Parse(std::string input, Base* tree);	//if initial input exists
        void setInput(std::string input);				//to be set by user during runtime
        int parse(); //returns null if no input, otherwise, returns a constructed tree
        std::string trim(std::string s);
        boolean badInput(int i, char connector);
};
#endif