
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include "hardproblem.h"

using namespace std;

Hardproblem::Hardproblem()
{
    difficulty = "Hard";
}

void Hardproblem::generateQuestion()
{
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<int> number(2, 10);
    uniform_int_distribution<int> operation(0, 3);

    int a = number(gen);
    int b = number(gen);
    int c = number(gen);
    int d = number(gen);

    int choice = operation(gen);

    switch (choice)
    {
        case 0: 
            question = to_string(a) + " + " +
                       to_string(b) + " * " +
                       to_string(c) + " = ?";

            correctAnswer = a + (b * c);
            break;

        case 1: 
            question = "(" + to_string(a) + " * " +
                       to_string(b) + ") + " +
                       to_string(c) + " = ?";

            correctAnswer = (a * b) + c;
            break;

        case 2: 
            question = to_string(a) + " - " +
                       to_string(b) + " * " +
                       to_string(c) + " = ?";

            correctAnswer = a - (b * c);
            break;

        case 3: 
            
            b = c * number(gen);

            question = to_string(a) + " + " +
                       to_string(b) + " / " +
                       to_string(c) + " * " +
                       to_string(d) + " + " +
                       to_string(a) + " = ?";

            correctAnswer = a + (b / c) * d + a;
            break;
    }
   
    cout << question << endl;
    
}
