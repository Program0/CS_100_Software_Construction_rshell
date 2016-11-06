//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "exit_command.h"

// Default constructor
Exit_Command::Exit_Command() {

}

// Issues the exit program program
int Exit_Command::execute() {
    // We return -1 to signify exit.
    return -1;
}

bool Exit_Command::isLeaf() {
    return true;
}
