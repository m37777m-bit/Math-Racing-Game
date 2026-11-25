#include "leaderboard.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void leaderboard:: addentry(string username, int score)
{
    rankings.push_back( LeaderboardEntry(username,score));
}
void leaderboard:: sortLeaderboard()
{
    
    const int SIZE= rankings.size();
    for (int i =0; i<SIZE-1; i++)
    {
        for(int n=i+1; i<SIZE; n++)
        {
            if (rankings[i].score <rankings[i].score)
            {
                swap(rankings[n],rankings[i]);
            }
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
void leaderboard:: saveToFile()//console -> txt/vector
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

    close.outfile();

}
void leaderboard:: LoadtoFile() //txt -> console/vector
{
    string username;
    int score;
    ifstream infile("data/leaderboard.txt")
    if(!infile)
    {
        cout <<"ERROR OPENING FILE: leaderboard.txt" <<endl;
        return;
    }
    while( infile >>username>> score;)
    {
        rankings.push_back(LeaderboardEntry(username,score));
    }

    infile.close();
    sortLeaderboard();
    
}