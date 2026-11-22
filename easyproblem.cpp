
#include <iostream>
#include <string>
#include <random>
#include "easyproblem.h"

using namespace std;

Easyproblem::Easyproblem()
{
    difficulty = "Easy";
}

void Easyproblem::generateQuestion()
{
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<int> number(1, 100);
    uniform_int_distribution<int> operation(0, 1);

    int a = number(gen);
    int b = number(gen);
    int choice = operation(gen);

    if (choice == 0)
    {
        question = to_string(a) + " + " + to_string(b) + " = ?";
        correctAnswer = a + b;
    }
    else
    {
        question = to_string(a) + " - " + to_string(b) + " = ?";
        correctAnswer = a - b;
    }

    cout << question << endl;
}
