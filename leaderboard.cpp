#include "leaderboard.h"
#include <iostream>
#include <string>
using namespace std;


void leaderboard:: addentry(string username, int score)
{
    rankings.push_back( LeaderboardEntry(username,score));
}
void leaderboard:: sortLeaderboard()
{
    int n=0;
    const int SIZE= rankings.size();
    for (int i =1; i<SIZE; i++)
    {
        if (rankings[n].score <rankings[i].score)
        {
            swap(rankings[n],rankings[i])
            n=i;
        }
    }
} 
void leaderboard:: displayLeaderBoard()
{
    cout <<"+++++++++++++++++++++++++++++" <<endl;
    cout <<"         LEADERBOARD         " <<endl;
    cout <<"+++++++++++++++++++++++++++++" <<endl;

    cout << "  RANKING         SCORE " <<endl;

    for (int i =0; i <rankings.size(); i++)
    {
        cout << i+1 << ") " << rankings[i].username << "          " <<rankings[i].score <<endl;
    }

    
}
void leaderboard:: saveToFile()
{

}
void leaderboard:: LoadtoFile()
{

}