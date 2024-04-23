#ifndef TASK3_HEADERS_H
#define TASK3_HEADERS_H


class Board {
protected:
    std::string board[6][7];
    int  moves = 0;
public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    void update_board (int x, int y, char symbol);
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    bool is_winner();
    // Return true if all moves are done and no winner
    bool is_draw();
    // Display the board and the pieces on it
    void display_board();
    // Return true if game is over
    bool game_is_over();
};

class X_O_Board : public Board{
    int gameChoice;
public:
    X_O_Board(int gameChoice);
    X_O_Board();
    void display_board();
    void update_board(int x, int y, char mark);
    bool is_winner();
    bool is_draw();
    bool isEmpty(int x, int y);
    bool activeIndex(int x, int y);
};

class Player {
protected:
    std::string name;
public:
    Player(std::string name);
    Player();
    std::string getName();
};

class RandomPlayer : public Player {
    int x, y, gameChoice;
public:
    RandomPlayer();
    void setGameChoice(int gamechoice);
    int getX();
    int getY();
};

class GameManager {
    int gameChoice;
    X_O_Board board;
    RandomPlayer comp;
    Player player_1, player_2;
    int x, y, choice;
    std::string winnersName;
public:
    GameManager(X_O_Board board, Player players[2], int gamechoice);

    void Run();
};

#endif