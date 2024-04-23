#include <iostream>
#include "Headers.h"

using namespace std;

//sets the board
X_O_Board::X_O_Board(int gameChoice) {
    this->gameChoice = gameChoice;
    if(gameChoice == 1){
        int k = 2;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 5; j++){
                if((i == 0 && j != 2) || (i == 1 && (j == 0 || j == 4))){
                    board[i][j] = "         ";
                }else {
                    board[i][j] = "|(" + to_string(i) + "," + to_string(j) + ")   ";
                    if(j == k){
                        board[i][j] += '|';
                        k++;
                    }
                }
            }
        }
    }
    else if(gameChoice == 2){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                board[i][j] = "|(" + to_string(i) + "," + to_string(j) + ")   ";
                if(j == 4){
                    board[i][j] += '|';
                }
            }
        }
    }
    else{
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                board[i][j] = "|(" + to_string(i) + "," + to_string(j) + ")   ";
                if(j == 4){
                    board[i][j] += '|';
                }
            }
        }
        board[0][3] += '|';
        board[0][4] = " ";
    }
}

X_O_Board::X_O_Board() {}

//displays the board
void X_O_Board::display_board() {
    int limit_I , limit_J;
    if(gameChoice == 1){
        limit_I = 3;
        limit_J = 5;
    }else if(gameChoice == 2){
        limit_I = 6;
        limit_J = 7;
    }else{
        limit_I = 5;
        limit_J = 5;
    }
    for(int i = 0; i < limit_I; i++){
        for(int j = 0; j < limit_J; j++){
            cout << board[i][j];
        }
        cout << "\n----------------------------------------------\n";
    }
}

//updates the board
void X_O_Board::update_board(int x, int y, char mark) {
    moves++;
    if (gameChoice == 1) {
        if ((x < 3 && x > -1) && (y < 5 && y > -1) && board[x][y][7] == ' ') {
            if (board[x][y] != "         ") {
                string updatedIndex = board[x][y];
                updatedIndex[7] = toupper(mark);
                board[x][y] = updatedIndex;
            }
        }
    }
    else if (gameChoice == 2) {
        if (!(x < 0 || x >= 6 || y < 0 || y >= 7) && (board[x][y][7] == ' ')) {
            // Find the lowest empty slot in the selected column
            for (int i = 5; i >= 0; i--) {
                if (board[i][y][7] == ' ') {
                    board[i][y][7] = toupper(mark);
                    break;
                }
            }
        }
    }
    else{
        if((x < 5 && x > -1) && (y < 5 && y > -1) && board[x][y][7] == ' '){
            string updatedIndex = board[x][y];
            updatedIndex[7] = toupper(mark);
            board[x][y] = updatedIndex;
        }
    }
}
//checks the board for winners
bool X_O_Board::is_winner() {
    if(gameChoice == 1){
        //checking rows
        int rowsCounter = 1;
        bool checkRows = false;
        for(int i = 1; i <= 2; i++){
            for (int j = (i == 1) ? 1:0; j < 5; j++){
                if(board[i][j] != "         " && board[i][j-1] != "         ") {
                    if(board[i][j][7] == board[i][j-1][7] && (board[i][j][7] == 'X' || board[i][j][7] == 'O')){
                        rowsCounter++;
                        if(rowsCounter == 3){
                            checkRows = true;
                            break;
                        }
                    }else{
                        rowsCounter = 1;
                    }
                }
            }
            if(checkRows){
                break;
            }
        }

        //checking columns
        int colCounter = 1;
        bool checkCol = false;
        for(int i = 1; i <= 2; i++){
            if(board[i][2][7] == board[i-1][2][7] && (board[i][2][7] == 'X' || board[i][2][7] == 'O')){
                colCounter++;
                if(colCounter == 3){
                    checkCol = true;
                    break;
                }
            }else{
                colCounter = 1;
            }
        }

        //checking diagonals
        bool checkDiag = false;
        if((board[0][2][7] == board[1][1][7]) && (board[0][2][7] == board[2][0][7]) && (board[0][2][7] == 'X' ||board[0][2][7] == 'O')){
            checkDiag = true;
        }else if((board[0][2][7] == board[1][3][7]) && board[0][2][7] == board[2][4][7]&& (board[0][2][7] == 'X' ||board[0][2][7] == 'O')){
            checkDiag = true;
        }


        if(checkRows || checkCol || checkDiag){
            return true;
        }else{
            return false;
        }
    }
    else if(gameChoice == 2){
        // Check for a win in rows
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j <= 7 - 4; ++j) {
                if (board[i][j][7] != ' ' &&
                    board[i][j][7] == board[i][j + 1][7] &&
                    board[i][j][7] == board[i][j + 2][7] &&
                    board[i][j][7] == board[i][j + 3][7]) {
                    return true;
                }
            }
        }

        // Check for a win in columns
        for (int j = 0; j < 7; ++j) {
            for (int i = 0; i <= 6 - 4; ++i) {
                if (board[i][j][7] != ' ' &&
                    board[i][j][7] == board[i + 1][j][7] &&
                    board[i][j][7] == board[i + 2][j][7] &&
                    board[i][j][7] == board[i + 3][j][7]) {
                    return true;
                }
            }
        }

        // Check for a win in diagonals (left-top to right-bottom)
        for (int i = 0; i <= 6 - 4; ++i) {
            for (int j = 0; j <= 7 - 4; ++j) {
                if (board[i][j][7] != ' ' &&
                    board[i][j][7] == board[i + 1][j + 1][7] &&
                    board[i][j][7] == board[i + 2][j + 2][7] &&
                    board[i][j][7] == board[i + 3][j + 3][7]) {
                    return true;
                }
            }
        }

        // Check for a win in diagonals (left-bottom to right-top)
        for (int i = 3; i < 6; ++i) {
            for (int j = 0; j <= 7 - 4; ++j) {
                if (board[i][j][7] != ' ' &&
                    board[i][j][7] == board[i - 1][j + 1][7] &&
                    board[i][j][7] == board[i - 2][j + 2][7] &&
                    board[i][j][7] == board[i - 3][j + 3][7]) {
                    return true;
                }
            }
        }

        return false;
    }
    else{
//checking rows
        int rowsCounter = 1;
        bool checkRows = false;
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                if (board[i][j][7] == board[i][j - 1][7] && (board[i][j][7] == 'X' || board[i][j][7] == 'O')) {
                    rowsCounter++;
                    if (rowsCounter == 3) {
                        checkRows = true;
                        break;
                    }
                } else {
                    rowsCounter = 1;
                }
            }
            if (checkRows) {
                break;
            }
        }

        //checking columns
        int colCounter = 1;
        bool checkCol = false;
        for (int j = 0; j < 5; j++) {
            for(int i = 1; i < 5; i++) {
                if(i == 0 && j == 4){
                    continue;
                }
                if (board[i][j][7] == board[i - 1][j][7] && (board[i][j][7] == 'X' || board[i][j][7] == 'O')) {
                    colCounter++;
                    if (colCounter == 3) {
                        checkCol = true;
                        break;
                    }
                } else {
                    colCounter = 1;
                }
            }
        }

        //checking diagonals
        bool checkDiag = false;
        if ((board[0][2][7] == board[1][3][7]) && board[0][2][7] == board[2][4][7] && (board[0][2][7] == 'X' || board[0][2][7] == 'O'))
            checkDiag = true;
        else if ((board[0][1][7] == board[1][2][7]) && board[0][1][7] == board[2][3][7] && (board[0][1][7] == 'X' || board[0][1][7] == 'O'))
            checkDiag = true;
        else if ((board[1][2][7] == board[2][3][7]) && board[1][2][7] == board[3][4][7] && (board[1][2][7] == 'X' || board[1][2][7] == 'O'))
            checkDiag = true;
        else if((board[0][0][7] == board[1][1][7]) && board[0][0][7] == board[2][2][7]&& (board[0][0][7] == 'X' ||board[0][0][7] == 'O'))
            checkDiag = true;
        else if((board[1][1][7] == board[2][2][7]) && board[1][1][7] == board[3][3][7]&& (board[1][1][7] == 'X' ||board[1][1][7] == 'O'))
            checkDiag = true;
        else if((board[2][2][7] == board[3][3][7]) && board[2][2][7] == board[4][4][7]&& (board[2][2][7] == 'X' ||board[2][2][7] == 'O'))
            checkDiag = true;
        else if((board[1][0][7] == board[2][1][7]) && board[1][0][7] == board[3][2][7]&& (board[1][0][7] == 'X' ||board[1][0][7] == 'O'))
            checkDiag = true;
        else if((board[2][1][7] == board[3][2][7]) && board[2][1][7] == board[4][3][7]&& (board[2][1][7] == 'X' ||board[2][1][7] == 'O'))
            checkDiag = true;
        else if((board[2][0][7] == board[3][1][7]) && board[2][0][7] == board[4][2][7]&& (board[2][0][7] == 'X' ||board[2][0][7] == 'O'))
            checkDiag = true;
        else if ((board[0][2][7] == board[1][1][7]) && (board[0][2][7] == board[2][0][7]) && (board[0][2][7] == 'X' || board[0][2][7] == 'O'))
            checkDiag = true;
        else if ((board[0][3][7] == board[1][2][7]) && (board[0][3][7] == board[2][1][7]) && (board[0][3][7] == 'X' || board[0][3][7] == 'O'))
            checkDiag = true;
        else if ((board[2][1][7] == board[1][2][7]) && (board[1][2][7] == board[3][0][7]) && (board[1][2][7] == 'X' || board[1][2][7] == 'O'))
            checkDiag = true;
        else if ((board[0][4][7] == board[1][3][7]) && (board[0][4][7] == board[2][2][7]) && (board[0][4][7] == 'X' || board[0][4][7] == 'O'))
            checkDiag = true;
        else if ((board[1][3][7] == board[2][2][7]) && (board[1][3][7] == board[3][1][7]) && (board[1][3][7] == 'X' || board[1][3][7] == 'O'))
            checkDiag = true;
        else if ((board[2][2][7] == board[3][1][7]) && (board[2][2][7] == board[4][0][7]) && (board[2][2][7] == 'X' || board[2][2][7] == 'O'))
            checkDiag = true;
        else if ((board[1][4][7] == board[2][3][7]) && (board[1][4][7] == board[3][2][7]) && (board[1][4][7] == 'X' || board[1][4][7] == 'O'))
            checkDiag = true;
        else if ((board[3][2][7] == board[2][3][7]) && (board[4][1][7] == board[2][3][7]) && (board[2][3][7] == 'X' || board[2][3][7] == 'O'))
            checkDiag = true;
        else if ((board[2][4][7] == board[3][3][7]) && (board[2][4][7] == board[4][2][7]) && (board[2][4][7] == 'X' || board[2][4][7] == 'O'))
            checkDiag = true;

        if(checkRows || checkCol || checkDiag){
            return true;
        }else{
            return false;
        }
    }
}

//checks if it's a draw i.e. checks if 9 moves have been played
bool X_O_Board::is_draw() {
    if((moves == 9 && gameChoice == 1) || (moves == 42 && gameChoice == 2) || (moves == 24 && gameChoice == 3)){
        return true;
    }else{
        return false;
    }
}

//checks if the chosen index in the board is empty or not
bool X_O_Board::isEmpty(int x, int y) {
    if(board[x][y][7] == ' '){
        return true;
    }else{
        return false;
    }
}

//checks if the chosen index in the board is active or not
bool X_O_Board::activeIndex(int x, int y) {
    if(board[x][y] != "         "){
        return true;
    }else{
        return false;
    }
}