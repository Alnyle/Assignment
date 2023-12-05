#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <iostream>
#include <cstdlib>
using namespace std;

#pragma once

class Game_OF_Life
{
public:
    Game_OF_Life();
    ~Game_OF_Life();
    bool initialize();
    void display();
    int count_neighbors(int i, int j);
    void reset();
    void run(int times);
    void next_generation();
    bool stop(char key);
    void row_line();
    void getRandMove(int& i, int& j);

private:
    int **board;
    int n_rows, n_cols;
};

#endif