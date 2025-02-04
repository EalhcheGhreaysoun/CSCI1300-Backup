#include <iostream>
using namespace std;

int main()
{
    char grade;
    cout << "Provide a grade (A, B, C, D, or F):" << endl;
    cin >> grade;

    if (grade == 'A' || grade == 'B' || grade == 'C'){
        cout << "This is a passing grade." << endl;
    }
    else if (grade == 'D'){
        cout << "This grade passes with conditions." << endl;
    }
    else {
        cout << "This is a failing grade." << endl;
    }

    return 0;

}