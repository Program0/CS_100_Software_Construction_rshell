//Marlo Zeroth mzero001@ucr.edu 861309346
////Emmilio Segovia esego001@ucr.edu 861305177
#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <vector>
#include "base.h"

class Compositor : public Base
{
protected:
    std::vector<Base *> mem;

public:
    Compositor();

    void add();
    int execute();

};

#endif // COMPOSITOR_H
