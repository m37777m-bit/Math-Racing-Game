#include "player.h"
#include <iostream>

Player::Player(string username) {
    this->username = username;
    difficulty = "Unassigned";
    placementScore = 0;
    placementTime = 0;
    bestScore = 0;
    bestTime = 0;
    totalRaces = 0;
    carChoice = "Not Selected";
}

string Player::getUsername() const {
    return username;
}

string Player::getDifficulty() const {
    return difficulty;
}

int Player::getPlacementScore() const {
    return placementScore;
}

double Player::getPlacementTime() const {
    return placementTime;
}

int Player::getBestScore() const {
    return bestScore;
}
        
double Player::getBestTime() const {
    return bestTime;
}
        
int Player::getTotalRaces() const {
    return totalRaces;
}
        
string Player::getCarChoice() const {
    return carChoice;
}
        
void Player::setDifficulty(string difficulty) {
    this->difficulty = difficulty;
}
        
void Player::setPlacementResults(int placementScore, double placementTime) {
    this->placementScore = placementScore;
    this->placementTime = placementTime;
}
        
void Player::setCarChoice(string carChoice) {
    this->carChoice = carChoice;
}
        
void Player::updateRaceResult(int bestScore, double bestTime) {
    
    // user first race
    if (totalRaces == 0) {
        this->bestScore = bestScore;
        this->bestTime = bestTime;
    }

    // user scores higher
    else if (bestScore > this->bestScore) {
        this->bestScore = bestScore;
        this->bestTime = bestTime;
    }

    // user scores equal but time is faster
    else if (bestScore == this->bestScore && bestTime < this->bestTime) {
        this->bestTime = bestTime;
    }

    totalRaces += 1;
}
        
void Player::displayProfile() const {
    cout << "=======================================" << endl;
    cout << "           PLAYER PROFILE              " << endl;
    cout << "=======================================" << endl;

    cout << "\nUsername: " << username << endl;
    cout << "Difficulty: " << difficulty << endl;
    cout << "Selected Car: " << carChoice << endl;

    cout << "\n---------- PLACEMENT TEST -------------" << endl;
    cout << "\nScore: " << placementScore << "/10" << endl;
    cout << "Time: " << placementTime << " seconds" << endl;

    cout << "\n---------- RACING STATS ---------------" << endl;
    cout << "\nTotal Races: " << totalRaces << endl;
    cout << "Best Score: " << bestScore << "/10" << endl;
    cout << "Best Time: " << bestTime << " seconds" << endl;

    cout << "\n=======================================" << endl;
    cout << endl;
}

void Player::restoreStats(string difficulty, int placementScore, double placementTime, int bestScore, double bestTime, int totalRaces, string carChoice) {
    this->difficulty = difficulty;
    this->placementScore = placementScore;
    this->placementTime = placementTime;
    this->bestScore = bestScore;
    this->bestTime = bestTime;
    this->totalRaces = totalRaces;
    this->carChoice = carChoice;
}