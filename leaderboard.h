#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <iostream>
#include <string>
#include<vector>


using namepace std;

struct LeaderboardEntry
{
    LeaderboardEntry(string username, int score)
    {
        this->username=username;
        this->score=score;
    }
    string username;
    int score;
};

class Leaderboard
{
    public:
    void addentry(string username, int score);
    void sortLeaderboard();
    void displayLeaderBoard();
    void saveToFile();
    void LoadtoFile();
    private:
    vector<LeaderboardEntry> rankings;

};



