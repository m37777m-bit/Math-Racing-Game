
#include <iostream>
#include <string>
#include <random>
#include "mediumproblem.h"

using namespace std;

Mediumproblem::Mediumproblem()
{
    difficulty = "Medium";
}

void Mediumproblem::generateQuestion()
{
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<int> number(2, 100);
    uniform_int_distribution<int> operation(0, 1);

    int a = number(gen);
    int b = number(gen);

    int choice = operation(gen);

    if (choice == 0)
    {
        question = to_string(a) + " * " + to_string(b) + " = ?";
        correctAnswer = a * b;
    }
    else
    {
        int divisor = number(gen);
        int quotient = number(gen);
        int dividend = divisor * quotient;

        question = to_string(dividend) + " / " +
                   to_string(divisor) + " = ?";

        correctAnswer = quotient;
    }

    cout << question << endl;
}
