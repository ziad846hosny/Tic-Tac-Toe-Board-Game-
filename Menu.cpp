#include <iostream>
#include "Headers.h"

using namespace std;

//X_O_App
int main() {
    int playerChoice, gameChoice;
    string name;
    cout << "Welcome to FCAI Pyramid X-O Game. :)\n"
         << "Which game would you like to play ?\n"
         << "1- Pyramid Tic-Tac-toe\n"
         << "2- Four-in-a-row\n"
         << "3- 5x5 Tic-Tac-Toe\n";
    cin >> gameChoice;
    cout << "Great!\n"
         << "Press 1 if you want to play with computer: \n";
    cin >> playerChoice;
    Player players[2];
    cout << "Welcome Player 1\n";
    cout << "Please enter your name: ";
    cin >> name;
    players[0] = Player(name);
    if(playerChoice == 1) {
        players[1] = RandomPlayer();
    }else{
        cout << "Welcome Player 2\n";
        cout << "Please enter your name: ";
        cin >> name;
        cout << "\n";
        players[1] = Player(name);
    }
    X_O_Board board(gameChoice);
    GameManager generator(board, players, gameChoice);
    generator.Run();

    system ("pause");




    return 0;
}
