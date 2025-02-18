
#include <iostream>
using namespace std;

int main() {
    int x=4;
    int y=1;
    switch (y)
    {
    case 1:
        switch (x)
        {
            case 2:
                cout << "Yippee ";
            case 3:
                cout << "Kai ";
                break;
            case 4:
                cout << "test ";
            default:
                cout << "test3 ";
                break;
        }
    case 2:
        cout << "case 2" << endl;
        if (0 <= x && x < 2) {
            cout << "test 2 ";
        } else if (x < 4) {
            cout << "Yai ";
        }
        if (x < 6) {
            cout << "test 5 ";
        }
        cout << "test 4 ";
    default:
        if (0 >= x && x < 3) {
            cout << "Yai ";
        } else if (x < 4) {
            cout << "Yay ";
        } else if (x < 6) {
        if (y > 2) {
            cout << "Yippee ";
        } else {
            cout << "Kai ";
        }
        }
    }
    return 0;
}