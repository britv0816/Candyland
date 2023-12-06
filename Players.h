#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

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
        string _name;
        int _stamina;
        double _gold;
        vector<Candy> _inventory;
        string _effect;
        int _candy_amount;

    public:
        Player();
        Player(string, int, double, Candy[]);

        void loadPlayer();
        int getCandyAmount();
        void setStamina(int);
        int getStamina();
        void setGold(double);
        double getGold();
        void setType(string);
        string getType();
        void setEffectValue(string);
        string getEffectValue();
        void printInventory();
        Candy findCandy(string);
        bool addCandy(Candy);
        bool removeCandy(string);
};

#endif