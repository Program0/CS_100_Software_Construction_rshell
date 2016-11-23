// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#include "command.h"

// Main constructor

Command::Command(std::vector<std::string> input) {

    // We only process if the input is valid
    if (input.empty()) {
        throw std::invalid_argument("Invalid argument. Empty vector parameter.");
    }     
    else {
        // We prepare an array of cstrings to pass to execvp
        // Plus an extra for the null terminated string
        cmd = new char* [input.size() + 1];
        size = input.size();

        // Iterate through the vector and copy the strings 
        for (unsigned int i = 0; i < input.size(); i++) {
            cmd[i] = (char*) input.at(i).c_str(); // Ugly but need to cast
            cmd[i] = new char[input.at(i).size() + 1];
            std::strncpy(cmd[i], input.at(i).c_str(), input.at(i).size() + 1);
        }
        cmd[input.size()] = NULL;
    }
}

// Destructor

Command::~Command() {
    if (cmd) {
        // Delete the children first
        //for (int i = 0; cmd[i] != NULL; i++) {
        //delete cmd[i];
        //}
        // Now deallocate the parent
        delete [] cmd;
    }
}

// We are a leaf. We have no children.

Base * Command::get_left() {
    return NULL;
}

// We are a leaf. We have no children.

Base * Command::get_right() {
    return NULL;
}

// Since we have no children we do nothing

void Command::set_left(Base* left) {

}

// Since we have no children we do nothing

void Command::set_right(Base* right) {

}

// Always returns true. We are a leaf.

bool Command::isLeaf() {
    return true;
}

// Returns the contents of the command. If there are no
// commands returns an empty string

std::string Command::to_string() {
    std::string temp;
    if (cmd) {
        for (unsigned int i = 0; cmd[i] != NULL; i++) {
            temp += std::string(cmd[i]) + " ";
        }
    }
    return temp;
}

// Returns a vector of the contents. If there are no commands
// returns an empty vector.

std::vector<std::string> Command::to_vector() {
    std::vector<std::string> v;
    if (cmd) {

        for (unsigned int i = 0; cmd[i] != NULL; i++) {
            std::string temp(std::string(cmd[i]));
            v.push_back(temp);
        }
    }
    return v;
}
// We print out our data.

void Command::print() {
    if (cmd) {
        for (unsigned int i = 0; cmd[i] != NULL; i++) {
            std::cout << cmd[i] << " ";
        }
        std::cout << std::endl;
    }
}

// We execute

int Command::execute() {
    int returnValue;

    // Find which command to execute
    if (!std::strcmp(cmd[0], "exit")) {
        returnValue = exit_command();
    } else if (!std::strcmp(cmd[0], "test") || !std::strcmp(cmd[0], "[")) {
        returnValue = test_command();
    } else {
        returnValue = system_call();
    }

    // Return its value
    return returnValue;
}

// We issue the exit command

int Command::exit_command() {
    // We return -1 to signify exit.
    return -1;
}

// We issue the system call

int Command::system_call() {
    pid_t cpid, w; // pid of child and pid of process that has changed 

    // Assuming the call to execv succeeds we set status = 0 
    // and handle the result when call to execvp is made
    int status;

    int result; // final result after running execvp

    // Now we are almost ready to execute
    int exec_pipe[2]; // For communicating using a pipe

    // Create the pipe.
    if (pipe(exec_pipe)) {
        perror("pipe failed");
        return EXIT_FAILURE;
    }

    // We fork here and split into parent and child processes.
    if ((cpid = fork()) < 0) {
        perror("process failed");
        exit(EXIT_FAILURE);
    }// We are in the child process
    else if (cpid == 0) {

        // We close the read end of the pipe in the child
        close(exec_pipe[0]);

        // We call the fcntl function so that the child can set the FD_CLOEXEC flag
        // when exevp runs
        if (fcntl(exec_pipe[1], F_SETFD, fcntl(exec_pipe[1], F_GETFD) | FD_CLOEXEC)) {
            perror("fcntl failed");
            return EX_OSERR;
        }

        // Now we execute the command   
        if ((status = execvp(cmd[0], cmd)) == -1) {
            // Now we write the error number result to the pipe
            write(exec_pipe[1], &errno, sizeof (int));
            std::string temp(cmd[0]);
            std::string s(": command not found");
            temp += s;
            perror(temp.c_str());
        }

    } else {
        // We are in the parent process now
        // We make parent process wait for child processes to exit
        do {

            // We close the writing end of the pipe in parent
            close(exec_pipe[1]);

            //If there was an error during wait we exit 

            if ((w = waitpid(cpid, &status, WUNTRACED)) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    // Return the error number the child process stored in the pipe after execvp. 
    // If successfull it should return 0 or if it failed return the error number.
    result = read(exec_pipe[0], &errno, sizeof (errno));

    return result;
}

// We issue the test command

int Command::test_command() {
    //size_t size = PATH_MAX + 1;
    int status; // Return value after execution    
    //char *buffer1 = new char[PATH_MAX + 1]; /* not sure about the "+ 1" */
    //char *buffer2 = new char[PATH_MAX+1]; /* not sure about the "+ 1" */
    //std::string temp("../");
    //temp += std::string(cmd[2]);

    //char *resolvedPath = realpath(cmd[2], buffer1);

    //char *currentDir = getcwd(buffer2, size);
    //if (resolvedPath) {


   // } else {
        //perror("Error");
    //}

    // We test whether we are dealing with     
    struct stat sb;

    // We check how the test command was passed. Either it there were flags or no flags.
    if (!std::strcmp(cmd[1], "-e") || !std::strcmp(cmd[1], "-d") 
            || !std::strcmp(cmd[1], "-f")) {
        // We test whether this is a file, directory or otherwise
        if (stat(cmd[2], &sb) == -1) {
            status = 1;
            //perror("stat"); // Outputs an error to the command line
        } else {
            // If it is either a directory or file
            if ((!std::strcmp(cmd[1], "-e")) && ((S_ISREG(sb.st_mode) == 1)
                    || (S_ISDIR(sb.st_mode) == 1))) {
                status = 0;
            }                // If it is a file only
            else if (!std::strcmp(cmd[1], "-f") && S_ISREG(sb.st_mode) == 1) {
                status = 0;
            }// If it is a directory only
            else if (!std::strcmp(cmd[1], "-d") && S_ISDIR(sb.st_mode) == 1) {
                status = 0;
            } else {
                status = 1;
            }
        }
    } else {
        // We test whether this is a file, directory or otherwise
        if (stat(cmd[1], &sb) == -1) {
            status = 1;
            //perror("stat"); // Outputs an error to the command line
        } else {
            // If it is either a directory or file we return true
            if (((S_ISREG(sb.st_mode) == 1) || (S_ISDIR(sb.st_mode) == 1))) {
                status = 0;
            } else {
                status = 1;
            }
        }
    }

    //delete buffer1;
    //delete buffer2;    
    // We output the success of the test function
    if (status == 0) {
        std::cout << "(True)" << std::endl;
    } else {
        std::cout << "(False)" << std::endl;
    }
    return status;
}

