// File name: A3_SheetPb6_20220737.cpp
// Purpose: program simulate Game of life
// Author(s):  Ahmed Elniel Esmaiel Adam      
// ID(s): 20220737
// Section: S11
// Date: 3/12/2023

#include <iostream>
#include<random>
#include <string>

using namespace std;

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

/* -------------- GameManager class ----------- */
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


/* ------------ Game_OF_Life_Board class implementation -------- */
Game_OF_Life_Board::Game_OF_Life_Board()
{
    n_rows = 20;
    n_cols = 20;
    board = new int*[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new int[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0; 
        }
    }
}

// set the board game
bool Game_OF_Life_Board::initialize()
{
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new int[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = rand() % 2; // get random value between 0 and 1
        }
    }

    return true;
}




// sets all the cell to 0 as dead cells
bool Game_OF_Life_Board::reset()
{

    for (int i = 0; i < n_cols; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
    }
    return true;
}

/// @brief print ---- for every square in the board
void Game_OF_Life_Board::row_line()
{

    cout << '\n';
    for (int i = 0; i < n_cols; i++)
    {
        cout << "----";
    }
    cout << '\n';
}

// display Game board
void Game_OF_Life_Board::display()
{
    row_line();
    for (int i = 0; i < n_rows; i++) {
        cout << ':';
        for (int j = 0; j < n_cols; j++) {
            cout << ' ' <<board[i][j] << " :";
        }
        row_line();
    }
}



// return the number of live neighbors of cell
int Game_OF_Life_Board::count_neighbors(int i, int j) {

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
bool Game_OF_Life_Board::next_generation() {

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
    return true;
}

// destructor to delete board 
Game_OF_Life_Board::~Game_OF_Life_Board()
{
    for (int i = 0; i < n_rows; i++)
    {
        // delete each row
        delete board[i];
    }
    // delete array of pointer
    delete[] board;
}


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


/* ------------ GameManager class implementation ------------ */

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

/* ----------- Player class implementation ------- */
// give player name
Player::Player(string name) {
    this->name = name;
}


/* ----------- main ------- */
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