#include "Board.h"
#include "Players.h"
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

int main()
{

    /*
    load candies from file
    ask # of players

    */

    Board board;
    int candy_store_index;

    Candy red = {"red", "red candy", 12, ""};
    Candy blue = {"blue", "blue candy", 24, ""};
    Candy green = {"green", "green candy", 36, ""};

    CandyStore a1("Olivia's store"), c2 ("Clarke's store"), c3 ("Lexa's store");

    // test cases
    assert(a1.addCandy(red));
    assert(a1.addCandy(blue));
    assert(a3.addCandy(green));

    CandyStore candy_stores[] = {a1, a2, a3};

    assert(board.addCandyStore(12));
    assert(board.addCandyStore(24));
    assert(board.addCandyStore(36));
    
    return 0;
}