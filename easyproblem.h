
#ifndef EASYPROBLEM_H
#define EASYPROBLEM_H

#include "mathproblem.h"

class Easyproblem : public Mathproblem
{
public:
    Easyproblem();
    void generateQuestion() override;
};

#endif
