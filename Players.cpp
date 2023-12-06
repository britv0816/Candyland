#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Players.h"
using namespace std;


Player::Player() {
    _name = "";
    _stamina = 0;
    _gold = 0.00;
    _candy_amount = 0;

    for (int i =0; i < _MAX_CANDY_AMOUNT; i++) {
        _inventory[i] = {"", "", 0.00, ""};
    }

    }

Player::Player(string name, int stamina, double gold, Candy player[]){
    _name = "";
    _stamina = stamina;
    _gold = gold;
    _candy_amount = 0;

    for (int i =0; i < _MAX_CANDY_AMOUNT && i < 15; i++) {
        _inventory.push_back(player[i]);

        if (player[i].name != "") {
    
            _candy_amount++;
        }
    }
}

/*
useCandy() {

    if (candy.name == )

}
*/

int Player::getCandyAmount(){
    return _candy_amount;

}

void Player::setStamina(int stamina) {
    _stamina = stamina;

}

int Player::getStamina(){
    return _stamina;

}

void Player::setGold(double gold) {
    _gold = gold;

}

// void setType(string effect_type) {
//     _effect_type = effect_type;
// }

// string getType() {
//     return _effect_type;
// }

double Player::getGold() {
    return _gold;

}

void Player::setEffectValue(string effect) {
    _effect = effect;

}

string Player::getEffectValue() {
    return _effect;

}

void Player::printInventory() {

    for(int i=0; i < _MAX_CANDY_AMOUNT; i+=3)
    {
        string empty;
        string blank;
        string blank2;

        cout << "|";

        if (_inventory[i].name == "") {
            empty = "[Empty]";
        }
        else {
            empty = "[" + _inventory[i].name + "]";

        }


        if (i+1 < _MAX_CANDY_AMOUNT && _inventory[i+1].name == "") {
            blank = "[Empty]";
        }
            else {
                blank = "[" + _inventory[i+1].name + "]";
            }

        if (i+2 < _MAX_CANDY_AMOUNT && _inventory[i+2].name == "") {
            blank2 = "[Empty]";
        }
            else {
                blank2 = "[" + _inventory[i+2].name + "]";
            }

        cout << empty << "|" ;
        cout << blank << "|" ; 
        cout << blank2 << "|" << endl;

    }

}

string lowerLetter(string str) {
    string result;
    for (int i =0; i <str.size(); i++) {
       result+= tolower(str[i]);
    }
    return result;
}

Candy Player::findCandy(string candy_name) {
    string orig = lowerLetter(candy_name);

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
        string trans = lowerLetter(_inventory[i].name);

        if (orig == trans) {
            return _inventory[i];
        }
    }

    return {"", "", "", 0.00,""};
}


bool Player::addCandy(Candy candy) {

    if (_candy_amount < _MAX_CANDY_AMOUNT) {
        for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
            if (_inventory[i].name == "") {
                _inventory[i] = candy;

                _candy_amount++;

                return true;
            }
        }
    }

    return false;
}


bool Player::removeCandy(string candy_name) {
     for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
        if (candy_name == _inventory[i].name) {
            for (int j = i; j < _MAX_CANDY_AMOUNT-1; j++)
            _inventory[j]= _inventory[j+1];

            _inventory[_MAX_CANDY_AMOUNT -1] = {"", "", 0.00, ""};

            _candy_amount--;

            return true;
        }
    }

    return false;
}

void Player::loadPlayer() {

    ifstream file_input;
    file_input.open("characters.txt");
    
    if (file_input.fail()) {
        cout << "Could not open file" << endl;
        return; 
    }

    string line = "";
    string name = "";

    while (getline(file_input, line)) {

        stringstream ss(line);
        string playersName = "";
        string candylist = "";

        getline(ss, playersName, '|');
        name = playersName;
        
        ss >> _stamina;
        ss.ignore();

        ss >> _gold;
        ss.ignore();

        getline (ss, candylist, '|');

        stringstream playerCandy(candylist);
        string name = "";

        while(getline(playerCandy, name, ",")) {
            if (_candy_amount < _MAX_CANDY_AMOUNT) {
                Candy candy = findCandy(name);
                _inventory.push_back(candy);
                _candy_amount++;
            }
        }
    }

    file_input.close();
}