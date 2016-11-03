//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef PARSE
#define PARSE

#include "base.h"
#include "compositor.h"
#include "semicolon_connector.h"
#include "or_connector.h"
#include "and_connector.h"
#include "command.h"
#include "comment.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

class Parse {
    private:
        std::string input;
        Base* tree = NULL;                          //the constructed tree will be set to be tree->child

    public:
        Parse(Base* tree);                          //if no input yet
        Parse(std::string input, Base* tree);       //if initial input exists
        void setInput(std::string input);           //to be set by user during runtime
        int parse();                                //returns success/failure int
        std::string trim(std::string str);
        bool badInput(std::string str, int &i, char connector);
};
#endif
