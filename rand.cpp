#include <iostream>
#include <cstdlib> // Include for rand() and srand()

using namespace std; 

void getColor(){

     // Seed the random number generator with a value (typically current time)
    srand(static_cast<unsigned>(time(nullptr))); // this is termed as seeding

    // Generate and print 5 random integers
        int color = rand() % 6;
        cout << "Random Number: " << color << endl;

    // cout << color << endl;

    // 1 will equal red
    if (color == 0) {
        cout << "Red" << endl;
        
    }

    // 2 will equal green
    else if (color == 1) {
        cout << "Green" << endl;

        
    }

    // 3 will equal cyan
    else if (color == 2) {
        cout << "Cyan" << endl;

        
    }

    // 4 will equal double red
    else if (color == 3) {
        cout << "D Red" << endl;

        
    }

    // 5 will equal double green
    else if (color == 4) {
        cout << "D Green" << endl;

        
    }

    // 6 will equal double cyan
    else if (color == 5) {
        cout << "D Cyan" << endl;

        
    }

    else {
        cout << "Error" << endl;

        return;
    }
}
int main() {

    getColor();

    // // Seed the random number generator with a value (typically current time)
    // srand(static_cast<unsigned>(time(nullptr))); // this is termed as seeding

    // // Generate and print 5 random integers
    //     int random_number = rand() % 6;
    //     cout << "Random Number: " << random_number << endl;

    return 0;
}