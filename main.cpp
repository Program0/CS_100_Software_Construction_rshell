#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

#include "test.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!"<<std::endl;
    pid_t child_pid;// Process id of the child after forking
    int child_status; // Status of child after fork() executes

    char *a = "ls";
    char *b[] = {"-la"};
    child_pid = fork();
    // If we successfully created a child
      if(child_pid == 0) {
        /* We succesfully created a child process. */
          pid_t piChild = waitpid(&child_status);
          if(piChild != child_pid)

        execvp(a, b);

        /* If execvp returns, it must have failed. */

        printf("Unknown command\n");
        exit(0);
      }
      else{

          std::cout << "Error: no child waiting"<<std::endl;
      }

    Test mytest;
    mytest.testCommand();
    return 0;

}
