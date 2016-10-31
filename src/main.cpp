// System libraries

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

// User libraries
#include "test.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!"<<std::endl;
    pid_t child_pid;// Process id of the child after forking
    int child_status; // Status of child after fork() executes

    child_pid = fork();
    // If we successfully created a child we should execute
    // commands here

      if (child_pid < 0){
          perror("Error: no child process created");
      }
      else if(child_pid == 0) {
          char *a[3];
          std::string l0 = "ls";
          std::string l1 = "-la";
          a[0] = (char *)l0.c_str();
          a[1] = (char *)l1.c_str();
          a[2] = NULL;

          std::cout << "Yay: we are in the child process:" << getpid() <<std::endl;
          execvp(a[0], a);
      }
      // The parent process will run here
      else{
          pid_t myID =  wait(&child_status);// waitpid(-1,&child_status,WNOHANG);
          std::cout << "Success. We are in the parent pid:" << myID << std::endl;

      }

    //Test mytest;
    //mytest.testCommand();
    return 0;

}
