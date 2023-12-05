#include <iostream>
#include "Game_OF_Life.h"
#include "Game_OF_Life.cpp"
using namespace std;

int main()
{

    Game_OF_Life game;
    int times;
    char key;
    while (true)
    {
        cout << "To start game press s:";
        cin >> key;
        if (key == 's' || key == 'S') {
            game.initialize();
            cout << "initialize board" << '\n';
            game.display();
        }
        else {
            break;
        }
        cout << "Many times to want to run the game: ";
        cin >> times;
        game.run(times);
    }
    
}