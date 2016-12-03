#!/bin/sh

#Should echo hello world
bin/rshell "echo hello world "

#should run ls -l
bin/rshell "ls -l"

#Should output main.cpp
bin/rshell "cat src/main.cpp"

#Should fail
bin/rshell "cd rshell/src/"

#Should exit
bin/rshell "exit"

#Should create a file named test.txt
bin/rshell "touch test.txt "

#Should clear screen
bin/rshell "clear"
