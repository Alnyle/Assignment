// File name: A3_SheetPb6_20220737.cpp
// Purpose: program simulate Game of life
// Author(s):  Ahmed Elniel Esmaiel Adam      
// ID(s): 20220737
// Section: S11
// Date: 3/12/2023

#include <iostream>
#include"BoardGame_Classes.hpp"

using namespace std;

GameManager::GameManager(board* matrix, Player* player) {
    boardArr = matrix;
    player = player;
}


// ---- complete here --- //

// run the Game for certain number of times
void GameManager::run(int times) {



    // if initialization for the board proccess happen correctly run the the game
    if (boardArr->initialize()) {
        cout << "Board initialized";
        boardArr->display();
        while(times) {

            boardArr->next_generation();
            cout << "Next generation" << '\n';
            boardArr->display();
            times--;
        }
    }


}


// run the again
void GameManager::runAgain(int times) {



    // if initialization for the board proccess happen correctly run the the game

    while(times) {
        boardArr->next_generation();
        cout << "Next generation" << '\n';
        boardArr->display();
        times--;
    }


}


bool GameManager::deadCells() {
    return boardArr->reset();
}

