#include "Game_OF_Life.h"




Game_OF_Life::Game_OF_Life()
{
}

// set the board cells
void Game_OF_Life::initialize()
{
    n_rows = 20;
    n_cols = 20;
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_rows];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
    }
}

// sets all the cell to 0 as dead cells
void Game_OF_Life::reset()
{

    for (int i = 0; i < n_cols; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
    }
}

/// @brief print ---- for every square in the board
void Game_OF_Life::row_line()
{

    cout << '\n';
    for (int i = 0; i < n_cols; i++)
    {
        cout << '-----';
    }
    cout << '\n';
}

// display Game board
void Game_OF_Life::display()
{
    row_line();
    for (int i = 0; i < n_rows; i++) {
        cout << ':';
        for (int j = 0; j < n_cols; j++) {
            cout << ' ' <<board[i][j] << ':';
        }
        row_line();
    }
}



// return the number of live neighbors of cell
int Game_OF_Life::count_neighbors(int i, int j) {

    int counter = 0;

    // condition >= if the = 1 (it's live) it's live if it's > 1 (it's was a live cell and became dead)

    if (i > 0 && board[i - 1][j] >= 1) counter++; // check top neighbor if it's live
    if (i < n_rows - 1 && board[i + 1][j] >= 1) counter++; // check bottom neighbor if it's live
    if (j > 0 && board[i][j - 1] >= 1) counter++; // // check left neighbor if it's live
    if (j < n_cols - 1 && board[i][j + 1] >= 1) counter++; // // check right neighbor if it's live
    if (i > 0 && j > 0 && board[i - 1][j - 1] >= 1) counter++; // // check top-left neighbor if it's live
    if (i < n_rows - 1 && j < n_cols - 1 && board[i + 1][j + 1] >= 1) counter++; // // check bottom-right neighbor if it's live
    if (i > 0 && j < n_cols - 1 && board[i - 1][j + 1] >= 1) counter++; // // check top-right neighbor if it's live
    if (i < n_rows - 1 && j > 0 && board[i + 1][j - 1] >= 1) counter++; // check if the bottom-left if it's live

    return counter;
}

// set the new life and dead cell
void Game_OF_Life::next_generation() {

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {

            // if cell is dead
            if (board[i][j] == 0) {
                // cell is became live because it's has three live neighbors
                if (count_neighbors(i, j) == 3) {
                    board[i][j] = -1; 
                }
            }

            // if cell is live
            else if (board[i][j] == 1) {

                // cell die if it's has less than two live neighbors
                if (count_neighbors(i, j) < 2) {
                    board[i][j] = 2;
                }

                // cell die if it's has more than three live neighbors
                else if (count_neighbors(i, j) > 3) {
                    board[i][j] = 2;
                }
            }
         }
    }


    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            // if has value -1 it's mean it's was dead and became live set and set it's value in the board to 1 (live)
            if (board[i][j] == -1) {
                board[i][j] = 1;
            }

             // if has value 2 it's mean it's was live and died set and set it's value in the board to zero (dead)
            else if (board[i][j] == 2) {
                board[i][j] = 0;
            }
        }
    }
}


// ---- complete here --- //

// // run the Game

// void Game_OF_Life::run() {

// }



Game_OF_Life::~Game_OF_Life()
{
    for (int i = 0; i < n_rows; i++)
    {
        // delete each row
        delete board[i];
    }
    // delete array of pointer
    delete[] board;
}
