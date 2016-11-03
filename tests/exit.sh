#!bin/sh

#Should exit after all commands are executed
./rshell "echo hello world && ls -l || exit "

#should exit immediately
./rshell "exit && ls -l || echo do not print "

#Should exit right after hello world
./rshell "echo hello world && exit || echo do not print "

#Should exit at end
./rshell "echo hello world && ls -l ; exit "

#Should exit
./rshell "exit"

#Should not exit
./rshell " # exit "

#Should not exit
./rshell "echo hello world exit && ls -l || echo do not print "

#Should not exit
./rshell "echo hello world && lm -l || eho do not print || exit "