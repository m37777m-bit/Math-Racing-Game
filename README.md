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
├── DataBase.txt
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
├── leaderboard.txt
│
├── data/
│   ├── players.txt
│   └── races.txt
│
└── README.md
```



## How to Compile and Run

### Requirements
- A C++ compiler (such as g++).
- Visual Studio Code or another C++ development environment.

### Compilation

From the project directory, compile the source files:

```bash
g++ -std=c++17 *.cpp -o math-racer
```

### Run

On macOS or Linux:

```bash
./math-racer
```

On Windows:

```bash
math-racer.exe
```

## How to Play

1. Launch Math Racer.
2. Choose whether to register as a new player or log in.
3. New players complete a 10-question placement test.
4. Select a car.
5. Answer 10 randomly generated math questions.
6. Move toward the finish line by answering correctly.
7. View your race results and leaderboard rankings.
8. Choose to race again or exit.

