#include <iostream>
#include <cstdlib>
#include "Headers.h"

using namespace std;


//sets the random player's name to computer
RandomPlayer::RandomPlayer() : Player(){
    name = "Computer";
}

void RandomPlayer::setGameChoice(int gamechoice) {
    this->gameChoice = gamechoice;
}

//returns a random x-coordinate
int RandomPlayer::getX() {
    int move;
    if(gameChoice == 1){
        move = 3;
    }else if(gameChoice == 2){
        move = 6;
    }else{
        move = 5;
    }
    x = rand() % move;
    return x;
}

//returns a random y-coordinate
int RandomPlayer::getY() {
    int move = (gameChoice == 2) ? 7:5;
    y = rand() % move;
    return y;
}