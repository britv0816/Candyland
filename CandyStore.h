#ifndef CANDY_STORE_H
#define CANDY_STORE_H

#include "Board.h"
#include "Players.h"
#include <iostream>
#include <vector>

using namespace std;

class CandyStore {
    private:
        string _store_name;
        const static int _MAX_CANDIES = 5;
        vector<Candy> _candies;
        int _candy_count;

    public:
        CandyStore();
        CandyStore(string);
        void loadCandies();
        bool addCandy(Candy);
        bool removeCandy(string candy_name);
        void displayCandies() const;

};

#endif