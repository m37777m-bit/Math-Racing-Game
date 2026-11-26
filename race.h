#ifndef RACE_H
#define RACE_H

#include<iostream>
#include <string>
#include "player.h"
using namespace std;

class Race {
    public:
    Race(Player& selected_player);
    void startRace();
    void displayTrack();

    private:
    Player &player;
    int position;
};

#endif
