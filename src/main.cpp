//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
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

