
#ifndef HARDPROBLEM_H
#define HARDPROBLEM_H

#include "mathproblem.h"

class Hardproblem : public Mathproblem
{
public:
    Hardproblem();
    void generateQuestion() override;
};

#endif
