// Class definition for Tic_Tac_Toy_SmartPlayer class
// Which is a computer player playing randomly
// Author:  Ahmed Esmaiel Adam
// Student: 20220737
// Date:  13/12/2023
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
SmartPlayer::SmartPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}






// int smartPlayer::miniMax(int& x, int& y,int depth, bool isMaximizing, bool firstTime = true) {
    
//     if (!theBoard->is_winner()) {
//         return 1;
//     }

//     if (isMaximizing) {

//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 if (theBoard->board[i][j] == ' ') {

//                 }
//             }
//         }

//     }

// }
