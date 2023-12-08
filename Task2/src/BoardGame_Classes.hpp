// File name: A3_SheetPb6_20220737.cpp
// Purpose: program simulate Game of life
// Author(s):  Ahmed Elniel Esmaiel Adam      
// ID(s): 20220737
// Section: S11
// Date: 3/12/2023

#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;
#include <string>
#pragma once

/* -------------- board class ------------------ */
class board
{
public:
    // return true if there the game board initialized;
    virtual bool initialize() = 0;

    // display game board
    virtual void display() = 0;

    // return number of life numbers
    virtual int count_neighbors(int i, int j) = 0;

    // Return true of cell cell are rested to dead
    virtual bool reset() = 0;

    // Return true if all can generate the next live cell in the next generation
    virtual bool next_generation() = 0;

    // return true if the is not q (quit)

    // print board lines
    virtual void row_line() = 0;



protected:
    int **board;
    int n_rows, n_cols;
};


/* -------------- Game of life class ------------------ */
class Game_OF_Life_Board : public board
{
public:
    Game_OF_Life_Board();
    ~Game_OF_Life_Board();
    bool initialize();
    void display();
    int count_neighbors(int i, int j);
    bool reset();
    bool next_generation();
    void row_line();
};


/* -------------- player class ------------------ */
class Player {
    protected: 
    string name;
    public:
    Player(string name);
    bool stop(char key);
};

/* -------------- GameManager class ------------------ */
class GameManager {
    private:
    board* boardArr;
    Player* player;
    public:
    GameManager(board* matrix, Player* player);
    void run(int times);
    void runAgain(int times);
    bool deadCells();
};

#endif