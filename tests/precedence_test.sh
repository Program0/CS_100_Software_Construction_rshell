#!bin/sh

# Should print A B C D
bin/rshell "(echo A && echo B) && (echo C && echo D)"

# Should print A B D
bin/rshell "(echo A && echo B) || echo C && echo D"

# Should print A B
bin/rshell "(echo A && echo B) || (echo C && echo D)"

# Should print A B
bin/rshell "(echo A && echo B) || (echo C && echo D)"

# Should print A B
bin/rshell "(echo A && (echo B || (echo C && echo D) ))"

# Should print A E
bin/rshell "echo A && (eco B && echo C || eco D) || echo E"

# Should print D
bin/rshell "(eco A && eco B) || (eco C || eco D)"

# Should print C ls -l cat src/main.cpp D
bin/rshell "(eco A && eco B) || echo C && (ls -l; cat src/main.cpp) && echo D"

# Should print C ls -l cat src/main.cpp D (True)
bin/rshell "(eco A && eco B) || (echo C && (ls -l; cat src/main.cpp) && echo D || clear) && test -e main.cpp"
