#include <iostream> // missing include iostream

using namespace std; // missing namespace

int main(){ // missing main function
    int day = 4;
    switch (day){ // missing curly brackets
        case 6:
            cout << "Today is Saturday";
            break;
        case 7:
            cout << "Today is Sunday";
            break;
        default: // missing colon
            cout << "Looking forward to the Weekend";
            break;
    }
}