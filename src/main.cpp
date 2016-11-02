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
    Test mytest;
    mytest.testCommand();
    return 0;

}

