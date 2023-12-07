#include <iostream>

#include "Board.h"
#include "Players.h"
#include "CandyStore.h"
#include "Game.h"
#include "Riddle.h"
#include "Tiles.h"

using namespace std;

    Games::Games() {
        /*
        start default, clean game clean start
        */
    }

    Games::Games(string) {
        /*
        implement an if/else structure which takes in user choice to be able to play either of the two games
        */
    }

    
    void playRockPaperScissors(Player players[2]) {
    // Check if either player has no candy available to bet
    if (players[0].getCandyAmount() <= 0 || players[1].getCandyAmount() <= 0) {
        cout << "Not enough candy!" << endl;
        return;
    }

    // Player 1's turn
    cout << "Player 1 Inventory" << endl;
    players[0].printInventory();

    // User input for Player 1
    string candy1;
  
    bool c1 = false;
    while (c1 == false) {
       
        cout << "Player 1: Select candy to bet" << endl;
        getline(cin.ignore(), candy1);
        if (players[0].findCandy(toLowerCase(candy1)).name != "") 
        {
            c1 = true;
            break;
        }

        while(c1 != true) 
        {
            cout << "Invalid selection!" << endl;
            getline(cin, candy1);
             if (players[0].findCandy(toLowerCase(candy1)).name != "") 
            {
                c1 = true;
                break;
            }
        }
    } ;

    // Player 2's turn
    cout << "Player 2 Inventory" << endl;
    players[1].printInventory();

    // User input for Player 2
    string candy2;
    bool c2 = false;
    while (c2 == false){
       
        cout << "Player 2: Select candy to bet" << endl;
        getline(cin, candy2);
        if (players[1].findCandy(toLowerCase(candy2)).name != "") 
        {
            c2 = true;
            break;
        } 
        while(c2 != true) 
        {
            cout << "Invalid selection!" << endl;
            getline(cin, candy2);
            if (players[1].findCandy(toLowerCase(candy2)).name != "") 
            {
                c2 = true;
                break;
            } 
        }
    };

    // Determine the winner
    char choice1, choice2;
   
    while (choice1 == choice2) {
        bool found1 = false;
        bool found2 = false;

        cout << "Player 1: Enter r, p, or s" << endl;
        cin >> choice1;

        if(choice1 == 'r' || choice1 == 'p' || choice1 == 's')
            found1 = true;

        while(found1 == false)
        {
             cout << "Invalid selection!" << endl;
             cin.clear();
             cin.ignore();
             cin >> choice1;
             if(choice1 == 'r' || choice1 == 'p' || choice1 == 's')
                found1 = true;
        }

        cout << "Player 2: Enter r, p, or s" << endl;
        cin >> choice2;

        if(choice2 == 'r' || choice2 == 'p' || choice2 == 's')
            found2 = true;
        
        while(found2 == false)
        {
             cout << "Invalid selection!" << endl;
             cin.clear();
             cin.ignore();
             cin >> choice2;
             if(choice2 == 'r' || choice2 == 'p' || choice2 == 's')
                found2 = true;
        }

        // Check for a tie
        if (choice1 == choice2) {
            cout << "Tie! Play again" << endl;
        }

    }

    // Determine the winner
    if ((choice1 == 'r' && choice2 == 's') ||
        (choice1 == 's' && choice2 == 'p') ||
        (choice1 == 'p' && choice2 == 'r')) 
    {
        cout << "Player 1 has won " << candy2 << " from player 2!" << endl;
        Candy wonCandy = players[1].findCandy(toLowerCase(candy2));
        players[1].removeCandy(toLowerCase(candy2));
        players[0].addCandy(wonCandy);
    } 
    else 
    {
        cout << "Player 2 has won " << candy1 << " from player 1!" << endl;
        Candy wonCandy = players[0].findCandy(toLowerCase(candy1));
        players[0].removeCandy(toLowerCase(candy1));
        players[1].addCandy(wonCandy);
    }

}