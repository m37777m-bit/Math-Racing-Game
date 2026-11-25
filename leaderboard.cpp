#include "leaderboard.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void Leaderboard:: addentry(string username, int score)
{
    rankings.push_back( LeaderboardEntry(username,score));
}
void Leaderboard:: sortLeaderboard()
{
    
    const int SIZE= rankings.size();
    for (int i =0; i<SIZE-1; i++)
    {
        for(int n=i+1; n<SIZE; n++)
        {
            if (rankings[i].score < rankings[n].score)
            {
                swap(rankings[n],rankings[i]);
            }
        }
    }
} 
void Leaderboard:: displayLeaderBoard()
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
void Leaderboard:: saveToFile()//console -> txt/vector
{
    ofstream outfile("data/leaderboard.txt");
    if(!outfile)
    {
        cout <<"ERROR OPENING FILE: leaderboard.txt" <<endl;
        return;
    }
    for(int i=0; i<rankings.size(); i++)
    {
        string username= rankings[i].username;
        int score=rankings[i].score;

        outfile<< username <<" " << score <<endl;
    }

    outfile.close();

}
void Leaderboard:: LoadtoFile() //txt -> console/vector
{
    string username;
    int score;
    ifstream infile("data/leaderboard.txt");
    if(!infile)
    {
        cout <<"ERROR OPENING FILE: leaderboard.txt" <<endl;
        return;
    }
    while( infile >>username>> score)
    {
        rankings.push_back(LeaderboardEntry(username,score));
    }

    infile.close();
    sortLeaderboard();
    
}