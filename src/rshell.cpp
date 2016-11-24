
#include "rshell.h"
RShell::RShell () {

    size_t size = PATH_MAX + 1; // Maximum length of buffer       
    char *host = new char[size]; // Holds the name of the current host
    char *buffer = new char[size]; // Holds the current directory
    char *dir = getcwd (buffer, size); // Gets the current directory

    // Struct of type passwd to hold pointer returned by getpwuid
    struct passwd *pws;

    // We search for the effective user ID of the calling process with
    // geteuid() then search with return value as the criteria for getpwuid() 
    // and store the return struct in pws 
    pws = getpwuid (geteuid ());

    // Set the current user name
    if (pws->pw_name != NULL) {
        userName = std::string (pws->pw_name);
    }

    // Set the current host name
    if ((gethostname (host, size)) == 0) {
        hostName = std::string (host);
    }

    // Set the current directory
    if (dir) {
        std::string temp (dir);
        currentDir = temp.substr (temp.find_last_of("/")+1);
    }
}
void RShell::execute (int argc, char* argv[]) {

    Tree *commandTree = new Tree (); // Holds and executes commands
    Parse *parser = new Parse (); // Parses user input
    std::vector< std::vector<std::string> > v; // Used to parse user input   

    // If we are getting arguments from the command line
    // we process here
    if (argc > 1) {
        // Get the arguments and create a string        
        std::string passedArguments;
        for (int i = 1; i < argc; i++) {
            passedArguments += std::string (argv[i]);
        }

        std::cout << userName << "@" << hostName << ": " << currentDir << "$ ";
        parser->setInput (passedArguments);
        int result = parser->parse (v);
        if (result == 0) {
            commandTree->build (v);
            commandTree->execute ();
            commandTree->clear ();
            v.clear ();
        }
    }
}
void RShell::execute () {
    Tree *commandTree = new Tree (); // Holds and executes commands
    Parse *parser = new Parse (); // Parses user input
    std::vector< std::vector<std::string> > v; // Used to parse user input
    std::string input; // String used to parse command line and use input    

    // If it is user input
    int noExit = 0;
    do {
        std::cout << userName << "@" << hostName << ": " << currentDir << "$ ";
        std::cin.sync ();
        std::getline (std::cin, input);
        parser->setInput (input);
        int result = parser->parse (v);
        if (result == 0) {
            commandTree->build (v);
            noExit = commandTree->execute ();
            commandTree->clear ();
            v.clear ();
        }
        updateDisplay();
    } while (noExit >= 0);

}

/* Utility Functions */

// Returns a string with the logged in user name
std::string RShell::getUser () {
    return userName;
}

// Returns a string with the host's name
std::string RShell::getHost () {
    return hostName;
}

// Updates the current rshell terminal displayed username, host, and current 
// directory.
void RShell::updateDisplay () {
    
    size_t size = PATH_MAX + 1; // Maximum length of buffer       
    char *host = new char[size]; // Holds the name of the current host
    char *buffer = new char[size]; // Holds the current directory
    char *dir = getcwd (buffer, size); // Gets the current directory

    // Struct of type passwd to hold pointer returned by getpwuid
    struct passwd *pws;

    // We search for the effective user ID of the calling process with
    // geteuid() then search with return value as the criteria for getpwuid() 
    // and store the return struct in pws 
    pws = getpwuid (geteuid ());

    // Set the current user name
    if (pws->pw_name != NULL) {
        userName = std::string (pws->pw_name);
    }

    // Set the current host name
    if ((gethostname (host, size)) == 0) {
        hostName = std::string (host);
    }

    // Set the current directory
    if (dir) {
        std::string temp (dir);
        currentDir = temp.substr (temp.find_last_of("/")+1);
    }
}
