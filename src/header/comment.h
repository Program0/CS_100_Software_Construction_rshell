//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef COMMENT_H
#define COMMENT_H
#include "base.h"

class Comment : Base {
    private:
        Base* commented;

    public:
        Comment(Base* child);
        int execute();

};
#endif
