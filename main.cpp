#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <fstream>
#include <sstream>

#include "player.h"
#include "playermanager.h"
#include "race.h"
#include "easyproblem.h"
#include "leaderboard.h"

using namespace std;

// Read a number without crashing on invalid input.
bool readNumber(int& number) {
    if (!(cin >> number)) {
        if (cin.eof()) return false;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

// Run the placement test for a new player.
bool runPlacement(Player& player, PlayerManager& manager) {
    int score = 0;
    const int totalQuestions = 10;

    cout << "\n========== PLACEMENT TEST ==========\n";
    cout << "Answer 10 math questions.\n";
    cout << "Your accuracy and speed determine your difficulty.\n";

    auto startTime = chrono::steady_clock::now();

    for (int i = 0; i < totalQuestions; i++) {
        Easyproblem question;
        double answer;

        cout << "\nQuestion " << i + 1
             << "/" << totalQuestions << endl;

        question.generateQuestion();

        cout << "Your answer: ";

        if (!(cin >> answer)) {
            if (cin.eof()) return false;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid answer. Counted as incorrect.\n";
            continue;
        }

        if (question.checkAnswer(answer)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect!\n";
        }
    }

    auto endTime = chrono::steady_clock::now();
    double elapsedTime =
        chrono::duration<double>(endTime - startTime).count();

    string difficulty;

    // Adjustable placement thresholds.
    if (score >= 9 && elapsedTime <= 60.0) {
        difficulty = "Hard";
    } else if (score >= 7) {
        difficulty = "Medium";
    } else {
        difficulty = "Easy";
    }

    player.setPlacementResults(score, elapsedTime);
    player.setDifficulty(difficulty);

    if (!manager.savePlayers()) {
        cout << "Error saving placement results!\n";
        return false;
    }

    cout << "\n========== PLACEMENT RESULTS ==========\n";
    cout << "Score: " << score << "/10\n";
    cout << "Time: " << elapsedTime << " seconds\n";
    cout << "Assigned Difficulty: " << difficulty << endl;

    return true;
}

// Let the player select a car.
bool selectCar(Player& player, PlayerManager& manager) {
    int choice;

    cout << "\n========== SELECT YOUR CAR ==========\n";
    cout << "1. Racing Car\n";
    cout << "2. Sports Car\n";
    cout << "3. Formula Car\n";
    cout << "4. Classic Car\n";

    while (true) {
        cout << "\nChoose a car (1-4): ";

        if (!readNumber(choice)) {
            if (cin.eof()) return false;
            cout << "Invalid input. Try again.\n";
            continue;
        }

        string selectedCar;

        switch (choice) {
            case 1:
                selectedCar = "Racing Car";
                break;
            case 2:
                selectedCar = "Sports Car";
                break;
            case 3:
                selectedCar = "Formula Car";
                break;
            case 4:
                selectedCar = "Classic Car";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        player.setCarChoice(selectedCar);

        if (!manager.savePlayers()) {
            cout << "Error saving car selection!\n";
            return false;
        }

        cout << "Selected: " << selectedCar << endl;
        return true;
    }
}

// Display the leaderboard for a difficulty level.
// Uses the best scores stored in data/players.txt.
void showLeaderboard(const string& difficulty) {
    ifstream file("data/players.txt");

    if (!file) {
        cout << "Could not open player data.\n";
        return;
    }

    Leaderboard board;
    string line;
    int entries = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string username, category, placementScore;
        string placementTime, bestScore, bestTime;
        string totalRaces, carChoice;

        if (!getline(ss, username, ',') ||
            !getline(ss, category, ',') ||
            !getline(ss, placementScore, ',') ||
            !getline(ss, placementTime, ',') ||
            !getline(ss, bestScore, ',') ||
            !getline(ss, bestTime, ',') ||
            !getline(ss, totalRaces, ',') ||
            !getline(ss, carChoice)) {
            continue;
        }

        if (category != difficulty) continue;

        try {
            int races = stoi(totalRaces);
            int score = stoi(bestScore);

            if (races > 0) {
                board.addentry(username, score);
                entries++;
            }
        } catch (const exception&) {
            continue;
        }
    }

    cout << "\nDifficulty: " << difficulty << endl;

    if (entries == 0) {
        cout << "No completed races in this category yet.\n";
        return;
    }

    board.sortLeaderboard();
    board.displayLeaderBoard();
}

// Register a player and return the matching Player object.
Player* registerNewPlayer(PlayerManager& manager) {
    string username;

    cout << "\n========== NEW PLAYER ==========\n";
    cout << "Enter a username: ";

    if (!(cin >> username)) return nullptr;

    if (manager.usernameExists(username)) {
        cout << "That username already exists!\n";
        return nullptr;
    }

    if (!manager.registerPlayer(username)) {
        cout << "Registration failed. Check username or file access.\n";
        return nullptr;
    }

    cout << "Welcome, " << username << "!\n";

    return manager.findPlayer(username);
}

// Find an existing player.
Player* loginPlayer(PlayerManager& manager) {
    string username;

    cout << "\n========== RETURNING PLAYER ==========\n";
    cout << "Enter your username: ";

    if (!(cin >> username)) return nullptr;

    Player* player = manager.findPlayer(username);

    if (player == nullptr) {
        cout << "Player not found!\n";
        return nullptr;
    }

    cout << "\nWelcome back, " << username << "!\n";
    player->displayProfile();

    return player;
}

// Menu after selecting a player.
void playerMenu(Player& player, PlayerManager& manager) {
    int choice;

    // Players without placement results must finish placement.
    if (player.getDifficulty() == "Unassigned") {
        if (!runPlacement(player, manager)) return;
    }

    if (player.getCarChoice() == "Not Selected") {
        if (!selectCar(player, manager)) return;
    }

    while (true) {
        cout << "\n========== PLAYER MENU ==========\n";
        cout << "Player: " << player.getUsername() << endl;
        cout << "Difficulty: " << player.getDifficulty() << endl;
        cout << "\n1. Start Race\n";
        cout << "2. View Profile\n";
        cout << "3. View Leaderboard\n";
        cout << "4. Change Car\n";
        cout << "5. Return to Main Menu\n";
        cout << "\nEnter choice: ";

        if (!readNumber(choice)) {
            if (cin.eof()) return;
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                Race race(player);
                race.startRace();

                // Race updates Player in memory.
                // Save that updated Player to disk.
                if (!manager.savePlayers()) {
                    cout << "Error saving race statistics!\n";
                }
                break;
            }

            case 2:
                player.displayProfile();
                break;

            case 3:
                showLeaderboard(player.getDifficulty());
                break;

            case 4:
                selectCar(player, manager);
                break;

            case 5:
                return;

            default:
                cout << "Invalid menu choice!\n";
                break;
        }
    }
}

int main() {
    PlayerManager manager;

    if (!manager.loadPlayers()) {
        cout << "Error: Could not load player data!\n";
        return 1;
    }

    int choice;

    while (true) {
        cout << "\n====================================\n";
        cout << "            MATH RACER\n";
        cout << "====================================\n";
        cout << "1. New Player\n";
        cout << "2. Returning Player\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice: ";

        if (!readNumber(choice)) {
            if (cin.eof()) break;
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        Player* currentPlayer = nullptr;

        switch (choice) {
            case 1:
                currentPlayer = registerNewPlayer(manager);
                break;

            case 2:
                currentPlayer = loginPlayer(manager);
                break;

            case 3:
                cout << "\nThanks for playing Math Racer!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        if (currentPlayer != nullptr) {
            playerMenu(*currentPlayer, manager);
        }
    }

    return 0;
}
