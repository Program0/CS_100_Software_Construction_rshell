/* 
 * File:   rshell.h
 * Author: super0
 *
 * Created on November 21, 2016, 9:27 AM
 */

#ifndef RSHELL_H
#define	RSHELL_H

#include "tree.h"
#include "parse.h"

class RShell{    
public:
    // Main constructor
    RShell() {};
    
    // Runs with command line input
    void execute(int argc, char *argv[]);
    
    // Runs with user input
    void execute();
    
};


#endif	/* RSHELL_H */

