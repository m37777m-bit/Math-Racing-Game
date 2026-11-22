#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
    private:
        string username;
        string difficulty;
        int placementScore;
        double placementTime;
        int bestScore;
        double bestTime;
        int totalRaces;
        string carChoice;

    public:
        Player(string username);
        string getUsername() const;
        string getDifficulty() const;
        int getPlacementScore() const;
        double getPlacementTime() const;
        int getBestScore() const;
        double getBestTime() const;
        int getTotalRaces() const;
        string getCarChoice() const;
        void setDifficulty(string difficulty);
        void setPlacementResults(int placementScore, double placementTime);
        void setCarChoice(string carChoice);
        void updateRaceResult(int bestScore, double bestTime);
        void displayProfile() const;
        void restoreStats(string difficulty, int placementScore, double placementTime, int bestScore, double bestTime, int totalRaces, string carChoice);
};

#endif