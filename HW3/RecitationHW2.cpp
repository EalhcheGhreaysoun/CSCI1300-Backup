#include <iostream>
using namespace std;

int main()
{
    int sides = 6;

    if (sides < 2) {
        cout << "Invalid input! A polygon must have at least 3 sides." << endl;
    }
    else if (sides == 3) {
        cout << "It is a triangle." << endl;
    }
    else if (sides == 4) {
        cout << "It is a quadrilateral." << endl;
    }
    else if (sides == 5) {
        cout << "It is a pentagon." << endl;
    }
    else {
        cout << "It is a general polygon." << endl;
    }

    return 0;

}