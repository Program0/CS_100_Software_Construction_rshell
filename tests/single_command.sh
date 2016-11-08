#!bin/sh

#Should echo hello world
./rshell "echo hello world "

#should run ls -l
./rshell "ls -l"

#Should output main.cpp
./rshell "cat rshell/src/main.cpp"

#Should fail
./rshell "cd rshell/src/"

#Should exit
./rshell "exit "

#Should create a file named test.txt
./rshell "touch test.txt "
