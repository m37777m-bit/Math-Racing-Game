#include<iostream>
#include "race.h"

Race::race(Player& selected_player) : player(selected_player), position(0)
{
}
Race::displayTrack()
{
    const int tracklength=40;
    cout <<"\n========== MATH RACER ==========\n\n";
    cout <<"START ";
    for(int i=0; i <tracklength; i++)
    {
        cout <<"-";
    }
    cout <<" FINISH\n";
    for(int i=0; i<position; i++)
    {
        cout  << " ";
    }
    cout <<player.getCarChoice() << endl;
    cout <<"\nProgress: " << position << "/" <<tracklength << endl;

}
void Race:: startRace()
{
    int score=0;
    const int totalQuestions=10;
    cout <<"===WELCOME ";
    player.username()
    cout<<" ===\n";


    for(int i=0; i <10; i++)
    {
        user_response=0;
        switch (player.getDifficulty())
        {
            display();
            position++;
            case "Easy":
                Mathproblem question = new Easyproblem();
               cout <<"QUESTION " <<i+1 <<"/" <<totalQuestions<< ": "<< question.generateQuestion() <<endl;
                cout <<"RESPONSE:  ";
                cin>>user_response;
                 if (question.correctAnswer()==user_response) 
                {
                   cout <<"CORRECT!"<<endl;
                   score++;
                   position+=4;
                   if(position>tracklength)
                   {
                    position= tracklength;
                   }
                }
                else
                {
                    cout <<"INCORRECT"<<endl;
                }
                
                break;
            case "Medium":
                Mathproblem question= new Mediumproblem();
                cout <<"QUESTION " <<i+1 <<"/" <<totalQuestions<< ": "<< question.generateQuestion() <<endl;
                cout <<"RESPONSE:  ";
                cin>>user_response;
                


                if (question.correctAnswer()==user_response) 
                {
                   cout <<"CORRECT!"<<endl;
                   score++;
                   position+=4;
                   if(position>tracklength)
                   {
                    position= tracklength;
                   }
                }
                else
                {
                    cout <<"INCORRECT"<<endl;
                }
                
                break;
            case "Hard":
                Mathproblem question = new Hardproblem();
                cout <<"QUESTION " <<i+1 <<"/" <<totalQuestions<< ": "<< question.generateQuestion() <<endl;
                cout <<"RESPONSE:  ";
                cin>>user_response;
                cout <<"RESPONSE:  ";
                 if (question.correctAnswer()==user_response) 
                {
                   cout <<"CORRECT!"<<endl;
                   score++;
                   position+=4;
                   if(position>tracklength)
                   {
                    position= tracklength;
                   }
                }
                else
                {
                    cout <<"INCORRECT"<<endl;
                }

        }


    }
    delete question;
}
   
   
