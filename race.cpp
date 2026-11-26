#include <iostream>
#include <string>
#include <chrono>

#include "race.h"
#include "mathproblem.h"
#include "easyproblem.h"
#include "mediumproblem.h"
#include "hardproblem.h"
#include "playermanager.h"

using namespace std;

const int TRACK_LENGTH = 40;

Race::Race(Player& selected_player)
    : player(selected_player), position(0)
{
}

void Race::displayTrack()
{
    cout << "\n========== MATH RACER ==========\n\n";

    cout << "START ";

    for (int i = 0; i < TRACK_LENGTH; i++)
    {
        cout << "-";
    }

    cout << " FINISH\n";

   
    for (int i = 0; i < position; i++)
    {
        cout << " ";
    }

    cout << player.getCarChoice() << endl;

    cout << "\nProgress: " << position
         << "/" << TRACK_LENGTH << endl;
}

void Race::startRace()
{
    int score = 0;
    int user_response = 0;
    int position = 0;
    auto startTime = chrono::steady_clock::now();

    const int totalQuestions = 10;

    cout << "\n=== WELCOME ";
    cout << player.getUsername();
    cout << " ===\n";

    cout << "\nYour car: " << player.getCarChoice() << endl;
    cout << "Difficulty: " << player.getDifficulty() << endl;

    displayTrack();

    for (int i = 0; i < totalQuestions; i++)
    {
        
        Mathproblem* question = nullptr;

       
        switch (player.getDifficulty()[0])
        {
            case 'E':
            case 'e':
                question = new Easyproblem();
                break;

            case 'M':
            case 'm':
                question = new Mediumproblem();
                break;

            case 'H':
            case 'h':
                question = new Hardproblem();
                break;

            default:
                cout << "Invalid difficulty level!" << endl;
                return;
        }

        cout << "\n--------------------------------\n";
        cout << "QUESTION " << i + 1 << "/"
             << totalQuestions << endl;

        cout << question->generateQuestion() << endl;
        cout << "RESPONSE: ";
        cin >> user_response;

        if (question->checkAnswer(user_response))
        {
            cout << "CORRECT!" << endl;
            score++;
            position += 4;
        }
        else
        {
            cout << "INCORRECT!" << endl;
            position += 1;
        }

        if (position > TRACK_LENGTH) position = TRACK_LENGTH;


      
        delete question;

        
        displayTrack();

       
        if (position >= TRACK_LENGTH)
        {
            cout << "\nYOU REACHED THE FINISH LINE!\n";
            break;
        }
    }

    auto endTime = chrono::steady_clock::now();

    double elapsedTime = chrono::duration<double>(endTime - startTime).count();

    player.updateRaceResult(score, elapsedTime);

    cout << "\n========== RACE RESULTS ==========\n";

    cout << "Player: " << player.getUsername() << endl;

    cout << "Final Score: " << score
         << "/" << totalQuestions << endl;

    cout << "Final Position: "
         << position << "/" << TRACK_LENGTH << endl;

    cout << "Race Time: " << elapsedTime << " seconds" << endl;

    if (position >= TRACK_LENGTH)
    {
        cout << "Congratulations! You finished the race!\n";
    }
    else
    {
        cout << "Race completed! Better luck next time!\n";
    }

    cout << "==================================\n";
}
