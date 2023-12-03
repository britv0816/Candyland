#ifndef GAMES_H
#define GAMES_H
#include <iostream>
using namespace std;

 class Games {
    private:

    string riddle_;
    string paper_;
    string scissors_;
    string rock_;

    public:

    Games();
    Games(string);
    string getRock();
    string getPaper();
    string getScissors();
    string getRiddle();

    };

    #endif
/* 

*/