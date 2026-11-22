
#include <iostream>
#include <string>
#include "mathproblem.h"

using namespace std;


Mathproblem::Mathproblem()
{
    question = "NONE";
    correctAnswer = 0;
    difficulty = "NONE";
}


Mathproblem::~Mathproblem() = default;


void Mathproblem::displayQuestion()
{
    cout << question << endl;
}


bool Mathproblem::checkAnswer(double Answer)
{
    if (correctAnswer == Answer)
    {
        return true;
    }

    return false;
}


string Mathproblem::getDifficulty() const
{
    return difficulty;
}
