#include "playermanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <cmath>

using namespace std;

bool PlayerManager::usernameExists(string username) {
    for (size_t i = 0; i < gamePlayers.size(); i++) {
        if (gamePlayers[i].getUsername() == username) {
            return true;
        }
    }

    return false;
}

bool PlayerManager::registerPlayer(string username) {
    if (username.empty() ||
        username.find(',') != string::npos ||
        username.find('\n') != string::npos ||
        username.find('\r') != string::npos) {
        return false;
    }

    if (!usernameExists(username)) {
        Player user(username);
        gamePlayers.push_back(user);

        if (!savePlayers()) {
            gamePlayers.pop_back();
            return false;
        }

        return true;
    }

    return false;
}

bool PlayerManager::savePlayers() {
    ofstream playerRecord("data/players.txt");

    if (!playerRecord) {
        return false;
    }

    for (size_t i = 0; i < gamePlayers.size(); i++) {
        playerRecord << gamePlayers[i].getUsername() << ","
                     << gamePlayers[i].getDifficulty() << ","
                     << gamePlayers[i].getPlacementScore() << ","
                     << gamePlayers[i].getPlacementTime() << ","
                     << gamePlayers[i].getBestScore() << ","
                     << gamePlayers[i].getBestTime() << ","
                     << gamePlayers[i].getTotalRaces() << ","
                     << gamePlayers[i].getCarChoice() << endl;
    }

    playerRecord.close();
    if (playerRecord) {
        return true;
    }

    return false;
}

bool PlayerManager::loadPlayers() {
    ifstream playerRecord("data/players.txt");

    if (!playerRecord.is_open()) {
        gamePlayers.clear();
        return true;
    }

    vector<Player> tempPlayers;
    unordered_set<string> seenUsernames;
    string line;

    while (getline(playerRecord, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string username, difficulty, carChoice;
        string placementScoreStr, placementTimeStr, bestScoreStr, bestTimeStr, totalRacesStr;

        if (!getline(ss, username, ',') ||
            !getline(ss, difficulty, ',') ||
            !getline(ss, placementScoreStr, ',') ||
            !getline(ss, placementTimeStr, ',') ||
            !getline(ss, bestScoreStr, ',') ||
            !getline(ss, bestTimeStr, ',') ||
            !getline(ss, totalRacesStr, ',') ||
            !getline(ss, carChoice)) {
            return false;
        }

        if (carChoice.find(',') != string::npos) {
            return false;
        }

        if (username.empty() || difficulty.empty() || carChoice.empty()) {
            return false;
        }

        if (!seenUsernames.insert(username).second) {
            return false;
        }

        if (difficulty != "Easy" && difficulty != "Medium" &&
            difficulty != "Hard" && difficulty != "Unassigned") {
            return false;
        }

        int placementScore, bestScore, totalRaces;
        double placementTime, bestTime;

        try {
            size_t pos;
            placementScore = stoi(placementScoreStr, &pos);
            if (pos != placementScoreStr.length()) return false;

            placementTime = stod(placementTimeStr, &pos);
            if (pos != placementTimeStr.length()) return false;

            bestScore = stoi(bestScoreStr, &pos);
            if (pos != bestScoreStr.length()) return false;

            bestTime = stod(bestTimeStr, &pos);
            if (pos != bestTimeStr.length()) return false;

            totalRaces = stoi(totalRacesStr, &pos);
            if (pos != totalRacesStr.length()) return false;
        } catch (const exception&) {
            return false;
        }

        if (!isfinite(placementTime) || !isfinite(bestTime)) {
            return false;
        }

        if (placementScore < 0 || placementScore > 10 ||
            bestScore < 0 || bestScore > 10 ||
            placementTime < 0 || bestTime < 0 || totalRaces < 0) {
            return false;
        }

        Player p(username);
        p.restoreStats(difficulty, placementScore, placementTime, bestScore, bestTime, totalRaces, carChoice);
        tempPlayers.push_back(p);
    }

    if (playerRecord.bad()) {
        return false;
    }

    gamePlayers = tempPlayers;
    return true;
}

Player* PlayerManager::findPlayer(string username) {
    for (size_t i = 0; i < gamePlayers.size(); i++) {
        if (gamePlayers[i].getUsername() == username) {
            return &gamePlayers[i];
        }
    }

    return nullptr;
}

void PlayerManager::displayRegistration() {
    string username;

    cout << "========== PLAYER REGISTRATION ==========" << endl;

    while (1) {
        cout << "\nEnter username: ";
        cin >> username;

        if (cin.fail()) {
            return;
        }

        if (username.empty() ||
            username.find(',') != string::npos ||
            username.find('\n') != string::npos ||
            username.find('\r') != string::npos) {
            cout << "\nInvalid username!" << endl;
            continue;
        }

        if (usernameExists(username)) {
            cout << "\nUsername already exists!" << endl;
            continue;
        }

        if (registerPlayer(username)) {
            cout << "\nRegistration successful!" << endl;
            cout << "Welcome " << username << "!" << endl;
            return;
        } else {
            cout << "\nError: Could not save player data!" << endl;
            return;
        }
    }
}

void PlayerManager::displayLogin() {
    string username;

    cout << "========== RETURNING PLAYER ==========" << endl;

    while (1) {
        cout << "\nEnter username: ";
        cin >> username;

        if (cin.fail()) {
            return;
        }

        Player* currentPlayer = findPlayer(username);

        if (currentPlayer == nullptr) {
            cout << "\nPlayer not found!" << endl;
        } else {
            cout << "\nWelcome back!" << endl;
            currentPlayer->displayProfile();
            return;
        }
    }
}

