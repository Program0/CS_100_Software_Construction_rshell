#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

#include "test.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!"<<std::endl;
    /*
    pid_t child_pid;// Process id of the child after forking
    int child_status; // Status of child after fork() executes

    char *a[] = {"ls","-la"};
    child_pid = fork();
    // If we successfully created a child we should execute
    // commands here
      if(child_pid == 0) {
          pid_t piChild = waitpid(&child_status);
          if(piChild != child_pid)

        execvp(a[0], a);
      }
      // We failed
      else if (child_pid < 0){
          std::cout << "Error: no child process created"<<std::endl;
      }
      // The parent process will run here
      else{
          std::cout<< "Success. We are in the parent."<<std::endl;

      }

      */
    Test mytest;
    mytest.testCommand();
    return 0;

}
