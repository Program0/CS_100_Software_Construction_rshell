/* 
 * File:   rshell.h
 * Author: super0
 *
 * Created on November 21, 2016, 9:27 AM
 */

#ifndef RSHELL_H
#define	RSHELL_H

// System Libraries
#include <unistd.h>

// User Libraries
#include "tree.h"
#include "parse.h"

class RShell{
private:
    /* Member variables */
    char * userName; // Name of the logged in user
    char * hostName; // Name of the host where the use is logged in.

    /* Utility functions */
    char *getUser();
    char *getHost();

public:
    // Main constructor
    RShell() {};
    
    // Runs with command line input
    void execute(int argc, char *argv[]);
    
    // Runs with user input
    void execute();
    
};


#endif	/* RSHELL_H */

