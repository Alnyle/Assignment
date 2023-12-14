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
Tic_Tac_Toe_Board::Tic_Tac_Toe_Board()
{
    n_rows = n_cols = 5;
    board = new char *[n_rows];

    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
    }
};

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise

bool Tic_Tac_Toe_Board::update_board(int x, int y, char mark)
{

    if (!(x < 0 || x > 4 || y < 0 || y > 4) && board[x][y] == 0)
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
    {
        return false;
    }
}

// Display the board and the pieces on it
void Tic_Tac_Toe_Board::display_board()
{

    for (int i : {0, 1, 2, 3, 4})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

bool Tic_Tac_Toe_Board::is_winner()
{

    for (int i = 0; i < 5; i++)
    {

        if (
            // check if the square if not fill fill first then check if there a winner (strike) in rows
            (board[i][0] != 0) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) && (board[i][3] == board[i][4]) ||
            // // check if there a winner (strike) in rows
            (board[0][i] != 0) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] == board[3][i]) && (board[3][i] == board[4][i]))
        {
            return true;
        }
    }

    // check diagonal from left to right if contain (strike) of same symbols "X" or "O" return true
    if ((board[0][0] != 0) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[3][3] == board[4][4]))
    {
        return true;
    }
    // check diagonal from right to left contain (strike) of same symbols "X" or "O" return true
    else if ((board[0][4] != 0) && (board[0][4] == board[1][3]) && (board[1][3] == board[2][2]) && (board[2][2] == board[3][1]) && (board[3][1] == board[4][0]))
    {
        return true;
    }
    else
    {
        // if there is no strike return false(there is no winner)
        return false;
    }
}

// return true if 25 moves are done and no winner
bool Tic_Tac_Toe_Board::is_draw()
{
    return (n_moves == 24 && !is_winner());
}

bool Tic_Tac_Toe_Board::game_is_over()
{
    return n_moves >= 24;
}

int Tic_Tac_Toe_Board::winnerPlayer() {

    // winning state 
    int player1 = 0,player2 = 0;
    for (int i = 0; i < 5; i++) {

        // check if there strike in rows
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') player1++;
        else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') player2++;

        if (board[2][i] == 'X' && board[3][i] == 'X' && board[4][i] == 'X') player1++;
        else if (board[2][i] == 'O' && board[3][i] == 'O' && board[4][i] == 'O') player2++;

        // check if there strike in columns
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') player1++;
        else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') player2++;
        if (board[i][2] == 'X' && board[i][3] == 'X' && board[i][4] == 'X') player1++;
        else if (board[i][2] == 'O' && board[i][3] == 'O' && board[i][4] == 'O') player2++;

    }

    ////////////////////////////////////////////
    // 1- check first diagonal from left to right
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') player1++;
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') player2++;
    // 2- check first diagonal from right to left
    if (board[0][2] == 'X' && board[1][3] == 'X' && board[2][4] == 'X') player1++;
    else if (board[0][2] == 'O' && board[1][3] == 'O' && board[2][4] == 'O') player2++;

    //////////////////////////////////////////////////////
    // 2- check second diagonal from left to right
    if (board[1][2] == 'X' && board[2][1] == 'X' && board[3][0] == 'X') player1++;
    if (board[1][2] == 'O' && board[2][1] == 'O' && board[3][0] == 'O') player2++;  


    // 2- check second diagonal from right to left
    if (board[1][2] == 'X' && board[2][3] == 'X' && board[3][4] == 'X') player1++;
    else if (board[1][2] == 'O' && board[2][3] == 'O' && board[3][4] == 'O') player2++;


    // 2- center of 2en diagonal
    if (board[1][2] == 'X' && board[2][1] == 'X' && board[1][3] == 'X') player1++;
    else if (board[1][2] == 'O' && board[2][1] == 'O' && board[1][3] == 'O') player2++;


    if (board[1][2] == 'X' && board[1][1] == 'X' && board[2][3] == 'X') player1++;
    else if (board[1][2] == 'O' && board[1][1] == 'O' && board[2][3] == 'O') player2++;


    ////////////////////////////////////////////////////////
    // 3 - check 3 diagonal from left to right
    // Bottom left diagonal
    if (board[2][2] == 'X' && board[3][1] == 'X' && board[4][0] == 'X') player1++;
    else if (board[2][2] == 'O' && board[3][1] == 'O' && board[4][0] == 'O') player2++;


    // top left diagonal
    if (board[2][2] == 'X' && board[1][1] == 'X' && board[0][0] == 'X') player1++;
    else if (board[2][2] == 'O' && board[1][1] == 'O' && board[0][0] == 'O') player2++;

    // top top right diagonal 
    if (board[2][2] == 'X' && board[1][3] == 'X' && board[0][4] == 'X') player1++;
    else if (board[2][2] == 'O' && board[1][3] == 'O' && board[0][4] == 'O') player2++;

    // bottom left diagonal
    if (board[2][2] == 'X' && board[3][3] == 'X' && board[4][4] == 'X') player1++;
    else if (board[2][2] == 'O' && board[3][3] == 'O' && board[4][4] == 'O') player2++;


    // center of 3rd diagonal
    if (board[2][2] == 'X' && board[3][3] == 'X' && board[1][1] == 'X') player1++;
    else if (board[2][2] == 'O' && board[3][3] == 'O' && board[1][1] == 'O') player2++;

    if (board[2][2] == 'X' && board[3][1] == 'X' && board[1][3] == 'X') player1++;
    else if (board[2][2] == 'O' && board[3][1] == 'O' && board[1][3] == 'O') player2++;


    ////////////////////////////////////////////
    // 4 - check 4th diagonal from left to right
    if (board[3][2] == 'X' && board[2][1] == 'X' && board[1][0] == 'X') player1++;
    else if (board[3][2] == 'O' && board[2][1] == 'O' && board[1][0] == 'O') player2++;


    // check 4th diagonal from left to right
    if (board[3][2] == 'X' && board[2][3] == 'X' && board[1][4] == 'X') player1++;
    else if (board[2][2] == 'O' && board[3][1] == 'O' && board[4][0] == 'O') player2++;

    // center if 4th diagonal
    if (board[3][2] == 'X' && board[4][1] == 'X' && board[2][3] == 'X') player1++;
    else if (board[3][2] == 'O' && board[4][1] == 'O' && board[2][3] == 'O') player2++;


    if (board[3][2] == 'X' && board[2][1] == 'X' && board[4][3] == 'X') player1++;
    else if (board[3][2] == 'O' && board[2][1] == 'O' && board[4][3] == 'O') player2++;


    ///////////////////////////////////////////
    // 5 - check 5th diagonal 
    // check 4th from right to left
    if (board[4][2] == 'X' && board[3][1] == 'X' && board[2][0] == 'X') player1++;
    else if (board[4][2] == 'O' && board[3][1] == 'O' && board[2][0] == 'O') player2++;

    // check 4th diagonal from left to right
    if (board[4][2] == 'X' && board[3][3] == 'X' && board[2][4] == 'X') player1++;
    else if (board[4][2] == 'O' && board[3][3] == 'O' && board[2][4] == 'O') player2++;



    // Check for no winner or tie
    if (player1 == player2) return 1;  // Tie
    if (player1 > player2 == 0) return 5;   // Player 1 wins
    if (player1 < player2) return -5;  // Player 2 wins

    // Default return (not clear what this represents)
    return 1;


}

// // to get smart move for the computer
// int Tic_Tac_Toe_Board::miniMax(int depth, bool isMaximizing, bool firstTime = true)
// {

//     int result = is_winner();
//     if (depth == 0 || result != 1)
//     { // depth = 0 (no other possible movement)
//         return result;
//     }

//     // check the empty cells -> all possible moves
//     if (isMaximizing)
//     {
//         int finalScore = INT_MIN;
//         int finalI, finalJ;
//         for (int i = 0; i < 5; i++)
//         {
//             for (int j = 0; j < 5; j++)
//             {
//                 if (board[i][j] == 0)
//                 {
//                     board[i][j] = 'X';
//                     int score = miniMax(depth - 1, false, false); // socre for every possible move
//                     board[i][j] = 0;                              // empty the cell again -> because it's just possible not actual move
//                     if (score > finalScore)
//                     {
//                         finalScore = score;
//                         finalI = i;
//                         finalJ = j;
//                     }
//                 }
//             }
//         }

//         if (firstTime)
//         {
//             board[finalI][finalJ] = 'O';
//             update_board(finalI, finalJ, 'O');
//         }

//         return finalScore;
//     }

//     else
//     {
//         int finalScore = INT_MAX; // store move score of best movement can move
//         int finalI, finalJ;       // store the best move with best score
//         for (int i = 0; i < 5; i++)
//         {
//             for (int j = 0; j < 5; j++)
//             {
//                 if (board[i][j] == 0)
//                 {
//                     board[i][j] = 'O';
//                     int score = miniMax(depth - 1, true, false);
//                     board[i][j] = 0;
//                     if (score < finalScore)
//                     {
//                         finalScore = score;
//                         finalI = i;
//                         finalJ = j;
//                     }
//                 }
//             } 
//         }

//         if (firstTime)
//         {
//             // board[finalI][finalJ] = 'O';
//             update_board(finalI, finalJ, 'O');
//         }

//         return finalScore;
//     }
// }

int Tic_Tac_Toe_Board::miniMax(int depth, bool isMaximizing, bool firstTime = false) {


  
    cout << "Worked";
    if(depth == 0 || is_winner() == false) {
        return 1;
    }
    else if (is_draw()) {
        return 0;
    }
    else if(game_is_over()) {
        return 1;
    }
    cout << "worked";
    if(isMaximizing) {
        int finalScore = -10;
        int finalI, finalJ;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << "Worked";
                if(board[i][j] == 0) {
                    cout << "worked";
                    board[i][j] = 'X';
                    int score = miniMax(depth - 1, false, false);
                    board[i][j] = 0;
                    if(score > finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                        cout << "worked";
                    }
                }
            }   
        }
 
        return finalScore;
    } else {
        int finalScore = 10;
        int finalI, finalJ;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = 'O';
                    int score = miniMax(depth - 1, true, false);
                    board[i][j] = 0;
                    if(score < finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                }
            }   
        }
        if(firstTime) {
            board[finalI][finalJ] = 'O';
        }
        return finalScore;
    }
}