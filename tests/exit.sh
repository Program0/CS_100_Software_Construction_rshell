#!bin/sh

#Should exit after all commands are executed
bin/rshell "echo hello world && ls -l || exit "

#should exit immediately
bin/rshell "exit && ls -l || echo do not print "

#Should exit right after hello world
bin/rshell "echo hello world && exit || echo do not print "

#Should exit at end
bin/rshell "echo hello world && ls -l ; exit "

#Should exit
bin/rshell "exit"

#Should not exit
bin/rshell " echo hello && echo world # exit "

#Should output #hello world# and not exit
bin/rshell "echo #hello && echo world#"

#Should not exit
bin/rshell "echo hello world exit && ls -l || echo do not print "

#Should not exit
bin/rshell "echo hello world && lm -l || eho do not print || exit "
