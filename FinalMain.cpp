#include "Board.h"
#include "Players.h"
#include "CandyStore.h"
#include "Game.h"
#include "Riddle.h"
#include "Tiles.h"

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

/*
Game needs to start by selecting character, each one being unique
Each turn is determind by colored cards
Special tiles can alter attributes or position
Be aware of stamina and low level
Player can use candies to alter other opponents or their own attributes
*/

/* 
load void function for players, show characters available. Store in a vector and display it.
during character selection, if not found in array/vector make sure user input is validated
*/

/*
 int generateCard()
 {
    int rand = 1 + (rand() % 6)// 1 to 6

    return rand;
 }

// int main()
// {

//     int C =  generateCard();
//     int counter =0;
//     if(C == 1)
//     {
//        while(getcolor() != Red)
//             move++;
//     }
//     elsee if(C == 2)
//     {
//        while(getcolor() != Green)
//             move++;
//     }
//     ...
//     else if(C == 5)
//     {
//         while(Counter != 2)
//         {
//             if(board.getColor() == "\033[;41m")
//             {
//                 Counter++; // Counter = 1
//             } 
//             if(Counter == 2)
//             {
//                 Counter = 0;
//                 break;
//             }
//         move++;
//         }
//     }
// }

// */

/*
string getColor()
{
    retrun _tile[_player_position].color;
}
*/

int main()
{

    Games game;
    Board board;
    Player player1;
    Player player2;
    
    int num_players;
    string name1;
    string name2;

    cout << "Welcome to the game of candyland. Please enter the number of players: " << endl;
    cin >> num_players;

    cout << "Enter player 1 name: " << endl;
    cin >> name1;

    cout << "Enter player 2 name: " << endl;
    cin >> name2;

    player1.loadPlayer();
    player2.loadPlayer();

    


    cout << "Begin game:" << endl;
    getColor();
    
    return 0;
}