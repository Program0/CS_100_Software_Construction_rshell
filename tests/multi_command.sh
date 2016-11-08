#!bin/sh

# Two connectors: && and ||
./rshell "echo hello world && ls -l || echo do not print "

#should issue error fail on cd
./rshell "echo hello world && ls -l || echo do not print; cd "

#Should fail with syntax error
./rshell "; echo hello world && ls -l || echo do not print "

#Should not output rest of line
./rshell "echo hello world && ls -l #|| echo do not print "

#Should output hello#world and rest of line
./rshell "echo hello#world && ls -l || echo do not print "

#Should not output anything after #
./rshell "echo hello world && ls -l # || echo do not print "

#Should output the #hello world and rest of lines
./rshell "echo #hello world && ls -l #|| echo do not print "

#Should not output rest of line after #
./rshell "echo # hello world && ls -l #|| echo do not print "