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