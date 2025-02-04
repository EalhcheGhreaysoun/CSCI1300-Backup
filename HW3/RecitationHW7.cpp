/*
Recitation HW 7.a
Psudocode:

get input glassesOfWater

if glassesOfWater < 3:
    print "You are falling behind! Drink more water! You have " + (7 - glassesOfWater) + " glasses left to drink."
else if glassesOfWater < 7:
    print "You're doing well! Keep it up! You still have " + (7-glassesOfWater) + " glasses left to drink."
else:
    print "Congratulations! You've hit your water goal for the day! Stay hydrated!"

*/

/*
Recitation HW 7.b

imagined examples of output:

example 1:
glassesOfWater = 2
output = You are falling behind! Drink more water! You have 5 glasses left to drink.

example 2:
glassesOfWater = 5
output = You're doing well! Keep it up! You still have 2 glasses left to drink.
*/

/*
Recitation HW 7.c
boundary conditions:
    the program should only process positive inputs. 
*/

// Recitation HW 7.d
#include <iostream>
using namespace std;

int main(){
    int glasses;
    cout << "How many glasses of water have you had today?" << endl;
    cin >> glasses;

    if (glasses >= 0){
        if (glasses < 3){
            cout << "You are falling behind! Drink more water! You have " << (7 - glasses) << " glasses left to drink." << endl;
        } else if(glasses < 7){
            cout << "You're doing well! Keep it up! You still have " << (7-glasses) << " glasses left to drink." << endl;
        }else {
            cout << "Congratulations! You've hit your water goal for the day! Stay hydrated!" << endl;
        }
    }else{
        cout << "You can't drink a negative number of glasses of water." << endl;
    }
}
