#!bin/sh

# Should output (True)
bin/rshell "test src/ "

# Should output (True)
bin/rshell "test src/main.cpp "

# Should output (True)
bin/rshell "test main.cpp "

# Should output (False)
bin/rshell "test /src/ "

# Should output (True)
bin/rshell "test -e src/ "

# Should output (True)
bin/rshell "test -f src/ "

# Should output (False)
bin/rshell "test -d src/ "

# Should output (True)
bin/rshell "test -e src/ "

# Should output (True)
bin/rshell "test -d rshell"

# Should output (True)
bin/rshell "test -d rshell/tests"

# Should output (True)
bin/rshell "test -d /usr/home/"

# Should output hello world and ls if test succeeds otherwise print do not print
bin/rshell "test -f src/main.cpp && echo hello world && ls -l || echo do not print "

# Test shoud fail and should print do not print after hello world and ls -l execute
bin/rshell "echo hello world && ls -l; test -f src/ || echo do not print; cd "

# Should fail with syntax error
bin/rshell "; test -e rshell && echo hello world && ls -l || echo do not print "

# Should output (True) and not output rest of line
bin/rshell "echo hello world && test -f src/main.cpp #|| echo do not print "


