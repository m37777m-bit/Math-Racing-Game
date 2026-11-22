
#ifndef MEDIUMPROBLEM_H
#define MEDIUMPROBLEM_H

#include "mathproblem.h"

class Mediumproblem : public Mathproblem
{
public:
    Mediumproblem();
    void generateQuestion() override;
};

#endif
