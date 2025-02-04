#include <iostream>
using namespace std;

int main()
{
    int angle = 40;
    if ( angle < 90 ) // x not defined, use angle
    {
        cout << "It is an acute angle." ;
    }
    else if( angle == 90 ) // x not defined, use angle
    {
        cout << "It is a right angle.";
    }
    else // else typed incorrectly
    {
        cout << "It is an obtuse angle.";
    }
}