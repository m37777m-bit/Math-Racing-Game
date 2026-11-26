#include "leaderboard.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include <vector>
using namespace std;

void Leaderboard:: addentry(string username, int score)
{
    rankings.push_back( LeaderboardEntry(username,score));
}
void Leaderboard::sortLeaderboard()
{
    const size_t SIZE = rankings.size();
    if (SIZE < 2) return;
    for (size_t i = 0; i < SIZE - 1; i++)
    {
        for (size_t n = i + 1; n < SIZE; n++)
        {
            if (rankings[i].score < rankings[n].score)
            {
                swap(rankings[i], rankings[n]);
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

    for (size_t i =0; i <rankings.size(); i++)
    {
        cout << i+1 << ") " << rankings[i].username << "          " <<rankings[i].score <<endl;
    }

    
}
void Leaderboard:: saveToFile()//console -> txt/vector
{
  ofstream outfile("data/leaderboard.txt");
    if (!outfile)
    {
        cout << "ERROR OPENING FILE: leaderboard.txt\n";
        return;
    }
    for (size_t i = 0; i < rankings.size(); i++)
    {
        outfile << rankings[i].username  << " " << rankings[i].score << endl;
    }
}
void Leaderboard:: LoadtoFile() //txt -> console/vector
{
   ifstream infile("data/leaderboard.txt");
    if (!infile)
    {
        cout << "ERROR OPENING FILE: leaderboard.txt\n";
        return;
    }
    rankings.clear();
    string username;
    int score;
    while (infile >> username >> score)
    {
        rankings.push_back(LeaderboardEntry(username, score));
    }

    infile.close(); 
    sortLeaderboard();
    
}