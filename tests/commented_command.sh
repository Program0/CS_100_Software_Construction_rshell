#!/bin/sh
#must be moved into rshell folder that was cloned!!!!!!!!!!!!
make clean; make

#Should not output anything after #
./bin/rshell "echo hello world && ls -l #|| echo do not print "

#should not output anything
./bin/rshell "#echo hello world && ls -l || echo do not print "

#Should not output anything
./bin/rshell "# echo hello world && ls -l #|| echo do not print "

#Should output world# and rest of line
./bin/rshell "echo hello world# && ls -l #|| echo do not print "

#Should output hello#world and rest of line
./bin/rshell "echo hello#world && ls -l #|| echo do not print "

#Should not output anything after #
./bin/rshell "echo hello world && ls -l # || echo do not print "

#Should output the #hello world and rest of lines
./bin/rshell "echo #hello world && ls -l #|| echo do not print "

#Should not output rest of line after #
./bin/rshell "echo # hello world && ls -l #|| echo do not print "
