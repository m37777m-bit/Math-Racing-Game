# Math-Racing-Game

Authors: Montserrat Mata & Shannon Liu

# Math Racer

## Project Description

Math Racer is a terminal-based racing game developed in C++.

Players compete in a math racing challenge by solving randomly generated math problems. Each correct answer moves their selected car closer to the finish line. Players are assigned a difficulty level based on their performance in an initial placement test.

The goal is to combine mathematical problem-solving, speed, and accuracy to achieve the best racing results.

## Features

### Player Management
- Register new players with unique usernames.
- Log in as returning players.
- Save and retrieve player information using text files.
- Track player performance across multiple sessions.

### Difficulty Levels
Players are categorized into three difficulty levels:

- **Easy:** Addition and subtraction.
- **Medium:** Multiplication and division.
- **Hard:** Multi-step mathematical expressions and mixed operations.

### Math Racing
- Complete 10 math questions per race.
- Receive one question at a time.
- Select a car to represent the player.
- Advance the car by answering questions correctly.
- Track accuracy and completion time.

### Results and Leaderboards
- Display final race results.
- Track personal performance history.
- Compare scores with other players in the same difficulty category.
- View player rankings.

### Data Persistence
Player profiles and race results are stored in local text files so that information can be retrieved when the program restarts.

## Technologies

- C++
- Object-Oriented Programming
- Inheritance and Polymorphism
- File Input/Output (`fstream`)
- Random Number Generation
- Time Measurement (`chrono`)
- Git and GitHub
- Visual Studio Code

## Project Structure

```text
math-racer/
│
├── main.cpp
│
├── player.h
├── player.cpp
├── playermanager.h
├── playermanager.cpp
│
├── mathproblem.h
├── mathproblem.cpp
├── easyproblem.h
├── easyproblem.cpp
├── mediumproblem.h
├── mediumproblem.cpp
├── hardproblem.h
├── hardproblem.cpp
├── Test_MathProblems.cpp
│
├── race.h
├── race.cpp
│
├── leaderboard.h
├── leaderboard.cpp
│
├── data/
│   ├── players.txt
│   ├── races.txt
|   └── leaderboard.txt
│
└── README.md
```



## How to Compile and Run

## Compilation and Execution

### Requirements
- C++ compiler (G++ recommended)
- C++17 or later
- Windows users: [MSYS2](https://www.msys2.org/) with the UCRT64 environment

### Compile the Project

Open a terminal in the project's root directory (the directory containing `main.cpp`).

Run the following command:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp race.cpp leaderboard.cpp mathproblem.cpp easyproblem.cpp mediumproblem.cpp hardproblem.cpp playermanager.cpp player.cpp -o mathgame
```

### Run the Game

**Windows (PowerShell):**
```powershell
.\mathgame.exe
```

**Linux / macOS:**
```bash
./mathgame
```

### Player Data

The game stores player information in:

```text
data/players.txt
```

This file stores usernames, difficulty levels, placement results, best race scores, race times, total races, and selected cars.

## Terminal Compatibility

The racing game uses Unicode emoji characters to display cars on the racing track.For the best visual experience:Use a terminal that supports UTF-8 encoding.Use a font that supports emoji rendering.On Windows, Windows Terminal or the VS Code integrated terminal is recommended.Emoji appearance may vary depending on the operating system and terminal font. If emojis are not supported, some characters may appear as boxes or question marks.

## How to Play

1. Launch Math Racer.
2. Choose whether to register as a new player or log in.
3. New players complete a 10-question placement test.
4. Select a car.
5. Answer 10 randomly generated math questions.
6. Move toward the finish line by answering correctly.
7. View your race results and leaderboard rankings.
8. Choose to race again or exit.

