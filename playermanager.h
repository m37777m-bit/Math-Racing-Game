#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "player.h"
#include<string>
#include<vector>

using namespace std;

class PlayerManager {
    private:
        vector<Player> gamePlayers;
    
    public:
        bool usernameExists(string username);
        bool registerPlayer(string username);
        bool savePlayers();
        bool loadPlayers();
        Player* findPlayer(string username);
        void displayRegistration();
        void displayLogin();
};

#endif