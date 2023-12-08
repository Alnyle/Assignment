// File name: A3_SheetPb6_20220737.cpp
// Purpose: program simulate Game of life
// Author(s):  Ahmed Elniel Esmaiel Adam      
// ID(s): 20220737
// Section: S11
// Date: 3/12/2023


#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;

int main()
{
    char key;
    int times;
    string playerName;
    Player *player;

    cout << "Welcome to Game of life Game.\n";

    cout << "please Enter your Name: ";
    cin >> playerName;
    player = new Player(playerName);

    cout << "How many times you want run the board: ";
    cin >> times;

    cout << '\n';

    GameManager gameOfLife (new Game_OF_Life_Board(), player);

    gameOfLife.run(times);


    bool reset = false;

    while (true)
    {

        cout << "To continue press any key...\n";
        cout << "To to stop press q \n";
        cout << "To reset the board press R \n";
        cin >> key;
        if (key == 'q' || key == 'Q') {
            break;
        }
        else if (key == 'R' || key == 'r') {
            gameOfLife.deadCells();
            reset = true;
        }
        else {
            
            int times;
            cout << "How many times you want to run the board: ";
            cin >> times;
            if (reset = true) {
                gameOfLife.run(times);
            }
            else 
                gameOfLife.runAgain(times);
        }
        

    }
}