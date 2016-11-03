//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177

// System libraries
#include <unistd.h> // For calling fork() and running commands as child
#include <sys/types.h> // For making a process wait until child finishes
#include <sys/wait.h> // For wait
#include <stdio.h> // For using perror() and catching errors if sys call failed
#include <cstdlib> // Basic c functions
#include <errno.h> // For outputting error after system call
#include <fcntl.h> // For testing a pipe
#include <sysexits.h> // For testing exit status of process

// User Libraries
#include "command.h"

// Accepts array of cstrings terminated by a null pointer
Command::Command(std::vector<std::string> input){
    cmd = input;
}

int Command::execute() {
std::cout << "command: <" << cmd.at(0) << ">" << std::endl;
    pid_t cpid, w;// pid of child and pid of process that has changed 

    // Assuming the call to execv succeeds we set status = 0 
    // and handle the result when call to execvp is made
    int status;

    int result; // final result after running execvp

    // We prepare an array of cstrings to pass to execvp
    // Plus an extra for the null terminated string
    char **a = new char* [cmd.size()+1];

    // Iterate through the vector and copy the strings 
    for(unsigned int i = 0; i<cmd.size();i++)
        a[i] = (char*) cmd.at(i).c_str(); // Ugly but need to cast
    a[cmd.size()]=NULL;

    // Now we are almost ready to execute
    int exec_pipe[2];// For communicating using a pipe
        
    // Create the pipe.
    if (pipe (exec_pipe))
    {
       perror("pipe failed");
       return EXIT_FAILURE;
     }

    // We call the fcntl function so that the child can set the FD_CLOEXEC flag
    // when exevp runs
    if (fcntl(exec_pipe[1], F_SETFD, fcntl(exec_pipe[1], F_GETFD) | FD_CLOEXEC)) {
        perror("fcntl failed");
        return EX_OSERR;
    }

    if((cpid = fork()) < 0) {
        perror("process failed");
        exit(EXIT_FAILURE);
    }

    // We are in the child process
    else if (cpid==0) {
        
        // We close the read end of the pipe in the child
        close (exec_pipe[1]);

        // Now we execute the command   
        if ((status = execvp(a[0],a)) == -1){
               perror(NULL);
        }

        // Now we write the result to the pipe
        write(exec_pipe[1], &errno, sizeof(int));
     }
    // We are in the parent process now
    // We make parent process wait for child processes to exit
    do {

       // We close the writing end of the pipe in parent
       close (exec_pipe[0]);
    
       //If there was an error during wait we exit 
       w = waitpid(cpid, &status, WUNTRACED);
       if (w == -1) {
            //perror("waitpid");
            exit(EXIT_FAILURE);
       }
       
   } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    
    delete a;
    // Return the pid of the successfull call (note if failed would -1)
   
    result = read(exec_pipe[0], &errno, sizeof(errno));
    // If there was something in the pipe other than 0 the process failed to execute
    return (result!=0)? -1 : 0;
}
