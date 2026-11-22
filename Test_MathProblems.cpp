#include <iostream>
#include "easyproblem.h"
#include "mediumproblem.h"
#include "hardproblem.h"



using namespace std;

int main()
{
    Easyproblem easy;
    Mediumproblem medium;
    Hardproblem hard;

    cout << "\n===== EASY =====" << endl;
    easy.generateQuestion();

  

    cout << "\n===== MEDIUM =====" << endl;
    medium.generateQuestion();

    cout << "\n===== HARD =====" << endl;
    hard.generateQuestion();

    return 0;
}
