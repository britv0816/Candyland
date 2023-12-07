#ifndef GAME_H
#define GAME_H

#include "Players.h"

class Game {
    private:
    Player my_character_;

    vector<Candy>candies;

    public:

    Game();
    Game(Player);

    void setMyCharacter();
    Player getMyCharacter();

    void loadPlayers();
    void pickStartCharacter();
    void startGame();

};

#endif
