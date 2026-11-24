#include<iostream>
#include "race.h"

Race::race(Player& selected_player) : player(selected_player)
{
}
void Race:: startRace()
{
    int score=0;
    for(int i=0; i <10; i++)
    {
        user_response=0;
        switch (player.getDifficulty())
        {
            case "Easy":
                Mathproblem question = new Easyproblem();
                question.generateQuestion();
                cout <<"RESPONSE:  ";
                if (question.correctAnswer()==user_response) score++;
                cout <<endl;
                
                break;
            case "Medium":
                Mathproblem question= new Mediumproblem();
                question.generateQuestion();
                cout <<"RESPONSE:  ";
                if (question.correctAnswer()==user_response) score++;
                cout <<endl;
                break;
            case "Hard":
                Mathproblem question = new Hardproblem();
                question.generateQuestion();
                cout <<"RESPONSE:  ";
                if (question.correctAnswer()==user_response) score++;
                 cout <<endl;
        }


    }

}
   
   
