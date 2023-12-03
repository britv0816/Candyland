#ifndef STORE_H
#define STORE_H

#include "Gameboard.h"
#include "Players.h"
#include <iostream>

using namespace std;

class CandyStore {
    private:
        string _store_name;
        const static int _MAX_CANDIES = 5;
        Candy _candies[_MAX_CANDIES];
        int _candy_count;

    public:
        CandyStore();
        CandyStore(string store_name);
        bool addCandy(Candy);
        bool removeCandy(string candy_name);
        void displayCandies() const;

};

#endif