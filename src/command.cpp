#include "command.h"

Command::Command(std::vector<std::string> n) {
    cmd = n;
}

int Command::execute() {
    pid_t pid; 

    int status; // To return the status of system call

    if((pid = fork()) < 0) {
        perror("process failed");
        exit(EXIT_FAILURE);
    }

    // We are in the parent process
    else if(pid!=0){    
        waitpid(pid,&status,0); 
       // We make parent process wait for child process to finish
    }

    // We are in the child process
    else {

        // Plus an extra for the null terminated string
        char **a = new char* [cmd.size()+1];

        // Iterate through the vector and copy the strings 
        for(unsigned int i = 0; i<cmd.size();i++)
            a[i] = (char*) cmd.at(i).c_str(); // Ugly but need to cast
        a[cmd.size()]=NULL;

        std::string s(a[0]);// For outputting the error
        
        // Deallocate 
//        for(unsigned int i = 0; i < cmd.size(); i++)
//            delete a[i];
        
        // Get the status of system call    
        if( (status = execvp(a[0],a)) == -1){
            s+=": command not found";
            perror(s.c_str());
        }
        delete a;
    }
    
    // Return the status if the call successfull or not
    return status;
}
