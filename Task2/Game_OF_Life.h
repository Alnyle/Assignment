#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#pragma once

class Game_OF_Life
{
public:
    Game_OF_Life();
    ~Game_OF_Life();
    bool update_screen (int x, int y);
    void display();
    int count_neighbors();
    void reset();
    void run(int times);
    void next_generation();
private:
    char** board;
    int n_rows, n_cols;

};

#endif