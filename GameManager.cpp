#include <iostream>
#include <string>
#include "Headers.h"

using namespace std;


//sets the board and the players for the game
GameManager::GameManager(X_O_Board board, Player *players, int gamechoice){
    this->gameChoice = gamechoice;
    this->board = board;
    this->player_1 = players[0];
    if(players[1].getName() == "Computer"){
        comp.setGameChoice(gameChoice);
        choice = 1;
    }else{
        player_2 = players[1];
        choice = 2;
    }
}

//runs the game, swaps turns between players
void GameManager::Run() {
    board.display_board();
    while (true){
        // 7warat player 1
        cout << player_1.getName() << " enter the coordinates of your turn: ";
        cin >> x >> y;
        while(!board.activeIndex(x, y)) {
            cout << player_1.getName() << " enter the coordinates of your turn: ";
            cin >> x >> y;
        }
        board.update_board(x, y, 'x');
        cout << "\n\n";
        board.display_board();
        //checking
        if(board.is_winner()){
            winnersName = player_1.getName();
            break;
        }else if(board.is_draw()){
            break;
        }

        //7warat player 2 if name == Computer
        if(choice == 1){
            x = comp.getX();
            y = comp.getY();
            while(true) {
                if(board.isEmpty(x, y) && board.activeIndex(x, y)){
                    board.update_board(x, y, 'o');
                    break;
                }else{
                    x = comp.getX();
                    y = comp.getY();
                }
            }
            cout << "\n\n";
            board.display_board();
            if(board.is_winner()){
                winnersName = comp.getName();
                break;
            }else if(board.is_draw()){
                break;
            }
        }else{
            //lw tl3 real life player
            cout << player_2.getName() << " enter the coordinates of your turn: ";
            cin >> x >> y;
            while(!board.activeIndex(x, y)) {
                cout << player_2.getName() << " enter the coordinates of your turn: ";
                cin >> x >> y;
            }
            board.update_board(x, y, 'o');
            cout << "\n\n";
            board.display_board();
            //checking
            if(board.is_winner()){
                winnersName = player_2.getName();
                break;
            }else if(board.is_draw()){
                break;
            }
        }
    }

    if(winnersName.empty()){
        cout << "It's a Draw\n";
    }else{
        cout << winnersName << " is the winner\n";
    }
}