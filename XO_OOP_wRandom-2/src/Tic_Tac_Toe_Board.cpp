// Class definition for Tic_Tac_Toe_Board
// Author:  Ahmed El-niel
// Date:    2/12/2023
// Version: 1

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// set Board
Tic_Tac_Toe_Board::Tic_Tac_Toe_Board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];

    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++) {
            board[i][j] = 0; 
        }
    }
};

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise

bool Tic_Tac_Toe_Board::update_board(int x, int y, char mark) {
    
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && board[x][y] == 0) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else {
        return false;
    }
}


// Display the board and the pieces on it
void Tic_Tac_Toe_Board::display_board() {
    
    for (int i: {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] <<" |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}



bool Tic_Tac_Toe_Board::is_winner() {

    for (int i = 0;i < 5;i++) {

        if (
        // check if the sqaure if not fill fill first then check if there a winner (strike) in rows
        (board[i][0] != 0) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) && (board[i][3] == board[i][4]) || 
        // // check if there a winner (strike) in rows
        (board[0][i] != 0) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] == board[3][i]) && (board[3][i] == board[4][i])) {
            return true;
        }
        }

        // check diagonal from left to right if contain (strike) of same symbols "X" or "O" return
        if ((board[0][0] != 0) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[3][3] == board[4][4])) {
            return true;
        }
        // check diagonal from right to left contain (strike) of same symbols "X" or "O" return
        else if ((board[0][4] != 0) && (board[0][4] == board[1][3]) && (board[1][3] == board[2][2]) && (board[2][2] == board[3][1]) && (board[3][1] == board[4][0])) {
            return true;
        }
        else {
            return false;
        }

}


// return true if 25 moves are done and no winner 
bool Tic_Tac_Toe_Board::is_draw() {
    return (n_moves == 25 && !is_winner());
}


bool Tic_Tac_Toe_Board::game_is_over() {
    return n_moves >= 25;
}

