#include <iostream>
#include <string>
#include "Headers.h"

using namespace std;


//sets the player's name
Player::Player(string name) {
    this->name = name;
}

//needed in the Random player's class
Player::Player() {}

//return's the players name
string Player::getName() {
    return name;
}