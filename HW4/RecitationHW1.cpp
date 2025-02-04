#include <iostream> // did not include iostream

using namespace std; //did not declare a namespace and did not use a namespace with cout and cin
int main (){ // did not have a main function
    char grade;
    cout << "Enter your grade (A, B, C, D, F): " << endl;
    cin >> grade;
    switch (grade) {
        case 'A': // did not use the correct char type
            cout << "Excellent work!" << endl;
            break; // add break
        case 'B':
            cout << "Good job!" << endl;
            break; // add break
        case 'C':
            cout << "You passed!" << endl;
            break; // add break
        case 'D':
            cout << "You need to work harder." << endl;
            break; // add break
        default:
            cout << "Invalid grade entered." << endl;
            break; // add break
    }
}