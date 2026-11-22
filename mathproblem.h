
#ifndef MATHPROBLEM_H
#define MATHPROBLEM_H

#include <iostream>
#include <string>

using namespace std;

class Mathproblem
{
public:
    Mathproblem();
    virtual ~Mathproblem();

    virtual void generateQuestion() = 0;

    void displayQuestion();
    bool checkAnswer(double Answer);
    string getDifficulty() const;

protected:
    string question;
    int correctAnswer;
    string difficulty;
};

#endif
