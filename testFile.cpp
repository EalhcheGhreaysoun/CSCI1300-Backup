#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    char inputCar;
    int days;

    cout << "Which car type (A, B, C, or D) would you like to rent?" << endl;
    cin >> inputCar;

    cout << "How many days would you like to rent this car?" << endl;
    cin >> days;


    if (days > 0){
        switch (inputCar)
        {
            case 'A':
                cout << fixed << setprecision(2) << "Your total is: $" << 1.23 * (80+days*15) << endl;
                break;
            case 'B':
                cout << fixed << setprecision(2) << "Your total is: $" << 1.23 * (80+days*15) << endl;
                break;
            case 'C':
                cout << fixed << setprecision(2) << "Your total is: $" << 1.23 * (80+days*15) << endl;
                break;
            case 'D':
                cout << fixed << setprecision(2) << "Your total is: $" << 1.23 * (80+days*15) << endl;
                break;    
            default:
                cout << "Please enter valid input." << endl;
                break;
        }
    } else {
        cout << "Please enter valid input." << endl;
    }
}