//Marlo Zeroth mzero001@ucr.edu 861309346
//Emmilio Segovia esego001@ucr.edu 861305177

#include "exit_command.h"

Exit_Command::Exit_Command(){

}

// Issues the exit program program
int Exit_Command::execute(){
    // We exit successfully
    exit(EXIT_SUCCESS);
    return 0;
}
