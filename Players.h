#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

struct Candy {
    string name;
    string description;
    string effect_type;
    int effect_value;
    double price;
    string candy_type;
};

class Player {
    private:
        int _MAX_CANDY_AMOUNT = 9;
        int _stamina;
        double _gold;
        Candy _inventory[9];
        int _candy_amount;

    public:
        Player();
        Player(int, int, double, Candy[], int);
        int getCandyAmount();
        void setStamina(int);
        int getStamina();
        void setGold(double);
        double getGold();
        void setType(string);
        string getType();
        void setEffect(string);
        string getEffect();
        void printInventory();
        Candy findCandy(string);
        bool addCandy(Candy);
        bool removeCandy(string);
};

#endif