#include <iostream>
#include "Riddle.h"

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

    string Games::getRock() {
        return rock_;
    }

    string Games::getPaper() {
        return paper_;
    }

    string Games::getScissors() {
        return scissors_;
    }

    string Games::getRiddle() {
        return riddle_;
    }
