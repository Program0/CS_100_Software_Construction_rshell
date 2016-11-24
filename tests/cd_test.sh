#!/bin/sh
#must be moved into rshell folder that was cloned!!!!!!!!!!!!
make clean; make

#this should change the current working directory to HOME
./bin/rshell "cd"

#this should take move the cwd back to where it was
./bin/rshell "cd -"

#this should change the cwd to the src folder
./bin/rshell "cd bin/src"

#this should be true since header folder is in src folder we are now in
./bin/rshell "test -f header"

#this should echo "a" and change the cwd back to the rshell folder
./bin/rshell "echo a && (eco b || eco c) || cd -"

#this shoud change the cwd directly to the header folder
./bin/rshell "cd src/header"

#these should all fail
./bin/rshell "cD; cd-; cd hope/this/is/fake; cd --; cd.."

#this should take the cwd back to rshell main folder
./bin/rshell "cd .. && cd .."
