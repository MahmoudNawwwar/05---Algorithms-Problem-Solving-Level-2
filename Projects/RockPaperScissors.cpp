/*
   Rock-Paper-Scissors game project using C++ where the player competes against the computer.
   The program reads the player's choice and generates a random choice for the computer.
   The winner is determined based on the standard game rules.
   Results for each round are displayed, counting wins and draws.
   After all rounds, the final winner is announced based on the number of wins.
   The user can choose to play again or exit the program.
   The code uses the <cstdlib> library for random number generation.
   Fixes: Removed invalid characters in enum, improved array indexing, and fixed Tabs printing.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults {
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner" };
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice) {
        case enGameChoice::Stone:
            return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
        case enGameChoice::Paper:
            return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
        case enGameChoice::Scissors:
            return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    }
    return enWinner::Draw;
}

string ChoiceName(enGameChoice Choice) {
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    return enWinner::Draw;
}

enGameChoice ReadPlayer1Choice() {
    short Choice;
    do {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return static_cast<enGameChoice>(Choice);
}

enGameChoice GetComputerChoice() {
    return static_cast<enGameChoice>(RandomNumber(1, 3));
}

stGameResults PlayGame(short HowManyRounds) {
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1) Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer) ComputerWinTimes++;
        else DrawTimes++;
    }

    stGameResults GameResults;
    GameResults.GameRounds = HowManyRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

void ShowFinalGameResults(stGameResults GameResults) {
    cout << "\nGame Rounds: " << GameResults.GameRounds;
    cout << "\nPlayer1 won times: " << GameResults.Player1WinTimes;
    cout << "\nComputer won times: " << GameResults.ComputerWinTimes;
    cout << "\nDraw times: " << GameResults.DrawTimes;
    cout << "\nFinal Winner: " << GameResults.WinnerName << "\n";
}

short ReadHowManyRounds() {
    short GameRounds;
    do {
        cout << "How Many Rounds (1 to 10)? ";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}

void StartGame() {
    char PlayAgain;
    do {
        srand((unsigned)time(NULL));
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowFinalGameResults(GameResults);
        cout << "\nDo you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    StartGame();
    return 0;
}
