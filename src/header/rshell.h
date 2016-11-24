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
#include <pwd.h>
#include <sys/types.h>

// User Libraries
#include "tree.h"
#include "parse.h"

class RShell{
private:
    /* Member variables */
    std::string userName; // Name of the logged in user
    std::string hostName; // Name of the host where the use is logged in.
    std::string currentDir; // Current working directory

public:
    // Main constructor
    RShell();
    
    // Runs with command line input
    void execute(int argc, char *argv[]);
    
    // Runs with user input
    void execute();
    
    /* Accessors */
    
    // Returns a string with the current logged in username
    std::string getUser();
    
    // Returns a string with the current host name
    std::string getHost();
    
    // Returns the current working directory of the rshell
    std::string getCurrentDir();
    
    // Refreshes the information to be displayed at the terminal
    void updateDisplay();
    
};


#endif	/* RSHELL_H */

