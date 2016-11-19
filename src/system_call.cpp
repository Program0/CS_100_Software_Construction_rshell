//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

// User Libraries
#include "system_call.h"

// Main constructor
// Accepts a vector of strings with cmd[0] being the command
// and parameters after cmd[0].
System_Call::System_Call(std::vector<std::string> input) : Command(input) {

}

// Executes the command with parameters stored in cmd vector. Assumes  
// command is stored at cmd[0] and parameters after cmd[0]. If successful 
// returns 0, otherwise it returns the error number to indicate failure.
int System_Call::execute() {
    pid_t cpid, w;// pid of child and pid of process that has changed 

    // Assuming the call to execv succeeds we set status = 0 
    // and handle the result when call to execvp is made
    int status;

    int result; // final result after running execvp

    // Now we are almost ready to execute
    int exec_pipe[2];// For communicating using a pipe
        
    // Create the pipe.
    if (pipe (exec_pipe))
    {
       perror ("pipe failed");
       return EXIT_FAILURE;
     }

 
    if ((cpid = fork()) < 0) {
        perror ("process failed");
        exit(EXIT_FAILURE);
    }

    // We are in the child process
    else if (cpid == 0) {
        
        // We close the read end of the pipe in the child
        close (exec_pipe[0]);
        
        // We call the fcntl function so that the child can set the FD_CLOEXEC flag
        // when exevp runs
        if (fcntl(exec_pipe[1], F_SETFD, fcntl(exec_pipe[1], F_GETFD) | FD_CLOEXEC)) {
            perror ("fcntl failed");
            return EX_OSERR;
        }

        // Now we execute the command   
        if ((status = execvp(cmd[0],cmd)) == -1){
            // Now we write the error number result to the pipe
            write (exec_pipe[1], &errno, sizeof (int));
            std::string temp ("No Command '");
            std::string c (cmd[0]);
            std::string f ("' found.");
            temp+=c + f;
            perror (temp.c_str());
        }

     }
     else {
           // We are in the parent process now
           // We make parent process wait for child processes to exit
           do {

           // We close the writing end of the pipe in parent
           close (exec_pipe[1]);
    
           //If there was an error during wait we exit 
           
           if ( (w = waitpid(cpid, &status, WUNTRACED)) == -1) {
               perror ("waitpid");
               exit(EXIT_FAILURE);
           }
       
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    // Return the error number the child process stored in the pipe after execvp. 
    // If successfull it should return 0 or if it failed return the error number.
    result = read (exec_pipe[0], &errno, sizeof(errno));

    return result;
}

