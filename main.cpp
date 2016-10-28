#include <cstdlib>
#include <iostream>

#include "test.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!"<<std::endl;
    Test mytest;
    mytest.testCommand();
    return 0;

}
