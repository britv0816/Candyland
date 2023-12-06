#include <iostream>
#include <fstream>
#include <sstream>
#include "CandyStore.h"
#include "Players.h"
// #include "Board.h"

using namespace std;

CandyStore::CandyStore() {
    _store_name = "";
    _candy_count = 0;
}

CandyStore::CandyStore(string) {
    _store_name = "";
    _candy_count = 0;
}

bool CandyStore::addCandy(Candy candy) {
    if (_candy_count == _MAX_CANDIES) {
        cout << "Unable to add candies to store." << _store_name << endl;
        return false;
    }
    _candies[_candy_count] = candy;
    _candy_count++;
    return true;
}

void CandyStore::displayCandies () const {
    if (_candy_count == 0) {
        cout << "No candies available in store: " << _store_name << endl;
        return;
    }

    cout << "Candies are present in store: " << _store_name << endl;
    for (int i = 0; i<_candy_count; i++) {
        cout << _candies[i].name << endl;
        return;
    }
}

void loadCandies(vector<Candy>candies) {
    ifstream file_input;
    file_input.open("candies.txt");
    
    if (file_input.fail()) {
        cout << "Could not open file" << endl;
        return; 
    }

    string line = "";

    while (getline(file_input, line)) {

        stringstream ss(line);
        Candy candy;

        getline(ss, candy.name, '|');
        getline(ss, candy.description, '|');
        getline(ss, candy.effect_type, '|');
        ss >> candy.effect_value;
        ss.ignore();

        getline (ss, candy.candy_type, '|');
        ss >> candy.price;

        candies.push_back(candy);
    }

    file_input.close();

}