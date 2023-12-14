// Class definition for Tic_Tac_Toe_App
// Author:  Ahmed Elniel Esmaiel Adam
// Date:    2/12/2023
// Version: 1

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
using namespace std;


int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to Tic Tac Toe. :)\n";
    cout << "Press 1 if you want to play with computer easy level: ";
    cout << "Press 2 if you want to play with computer hard level: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else if (choice == 1)
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);
    else if (choice == 2) 
        players[1] = new SmartPlayer('o', 5);
    // else 


    GameManager tic_tac_toe (new Tic_Tac_Toe_Board(), players);
    tic_tac_toe.run();
    system ("pause");
}