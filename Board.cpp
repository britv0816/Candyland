#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
    resetBoard();
}

/*
for the generateChance function
it should rand n0-100 % 100
if greater than 75 then fail
if = 50 1-5/5 
if less than 25 then 1-10/10 if both are above 75 then produce special tile
*/

void Board::generateChance() {

    int random = rand() % 100;

    if (random >= 30) {

    }

    else if (random <= 31 && random >= ) {
        
    }

}

void Board::updatePosition(int tiles) {

    /* create a rand functino that randomizes a number between 1-6 
    create the get color function and run if statements
    if current_color doesnt match card color or while(getcolor != cyan.green.red move +1)
    if a double is drawn, then while (getcolor != does not equal to cyan && counter !=2)
    counter != to 2
    return */
    
    // assign a new variable to adjust player's position
    // position plus tiles modded by 83
    int new_position = (_player_position + tiles) % _BOARD_SIZE;
    
    // Update the player's position
    _player_position = new_position;
}

void Board::getColor(){

    string tilesColor = _tiles[_player_position].color;

     // Seed the random number generator with a value (typically current time)
    srand(static_cast<unsigned>(time(nullptr))); // this is termed as seeding

    // Generate and print 5 random integers
        int color = rand() % 6;
        cout << "Random Number: " << color << endl;
        // cout << color << endl;

    int move = 0;

    // 1 will equal red
    if (color == 0) {

        cout << "Red" << endl;

        if (tilesColor == RED) {
        move = 3;
        }

        if (tilesColor == GREEN) {
        move = 2;
        }

        if (tilesColor == CYAN) {
        move = 1;
        }

        updatePosition(move);
        displayBoard();
    }

    // 2 will equal green
    else if (color == 1) {
        cout << "Green" << endl;

        if (tilesColor == GREEN) {
        move = 3;
        }

        if (tilesColor == CYAN) {
        move = 2;
        }

        if (tilesColor == RED) {
        move = 1;
        }

        updatePosition(move);
        displayBoard();
        
    }

    // 3 will equal cyan
    else if (color == 2) {
        cout << "Cyan" << endl;

        if (tilesColor == CYAN) {
        move = 3;
        }

        if (tilesColor == RED) {
        move = 2;
        }

        if (tilesColor == GREEN) {
        move = 1;
        }

        updatePosition(move);
        displayBoard();
    }

    // 4 will equal double red
    else if (color == 3) {
        cout << "D Red" << endl;

        if (tilesColor == RED) {
        move = 6;
        }

        if (tilesColor == GREEN) {
        move = 5;
        }

        if (tilesColor == CYAN) {
        move = 4;
        }

        updatePosition(move);
        displayBoard();
    }

    // 5 will equal double green
    else if (color == 4) {
        cout << "D Green" << endl;

        if (tilesColor == RED) {
        move = 6;
        }

        if (tilesColor == GREEN) {
        move = 5;
        }

        if (tilesColor == CYAN) {
        move = 4;
        }

        updatePosition(move);
        displayBoard();
    }

    // 6 will equal double cyan
    else if (color == 5) {
        cout << "D Cyan" << endl;

        if (tilesColor == RED) {
        move = 6;
        }

        if (tilesColor == GREEN) {
        move = 5;
        }

        if (tilesColor == CYAN) {
        move = 4;
        }

        updatePosition(move);
        displayBoard();
    }

    else {
        cout << "Error" << endl;

        return;
    }
}

void Board::resetBoard()
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {RED, GREEN, CYAN};
    Tile new_tile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }
    new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    _player_position1 = 0;
    _player_position2 = 0;
    _player_position3 = 0;
    _player_position4 = 0;

}

void Board::displayTile(int position)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    if (position == _player_position1)
    {
        cout << "1";
    }

    else if (position == _player_position2)
    {
        cout << "2";
    }

    else if (position == _player_position3)
    {
        cout << "3";
    }

    else if (position == _player_position4)
    {
        cout << "4";
    }
    else
    {
        cout << " ";
    }
    cout << " " << RESET;
}

void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition() const
{
    return _player_position;
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

bool Board::movePlayer(int tile_to_move_forward)
{
    int new_player_position = tile_to_move_forward + _player_position;
    if(new_player_position < 0 || new_player_position >= _BOARD_SIZE)
    {
        return false;
    }
    _player_position = new_player_position;
    return true;
}