// File name: A3_SheetPb6_20220737.cpp
// Purpose: program simulate Game of life
// Author(s):  Ahmed Elniel Esmaiel Adam      
// ID(s): 20220737
// Section: S11
// Date: 3/12/2023
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(string name) {
    this->name = name;
}

// bool Player::stop(char key) {
//     return key  == 'q';
// }

