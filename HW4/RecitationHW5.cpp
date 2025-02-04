/*
5.a pseudocode
variable initSpeed
variable roadType

get input initSpeed
get input roadType

if initSpeed <= 0:
    return: "invalid speed"
else if initSpeed < 20:
    if roadType == "Highway"
        return initSpeed + 8 * 25
    else if roadType == "City"
        return initSpeed + 5 * 25
    else if roadType == "Off-road"
        return initSpeed + 2 * 25
    else:
        return: "road type does not exist"
else if initSpeed < 60:
    if roadType == "Highway"
        return initSpeed + 10 * 25
    else if roadType == "City"
        return initSpeed + 7 * 25
    else if roadType == "Off-road"
        return initSpeed + 3 * 25
    else: 
        return: "road type does not exist"
else: 
    if roadType == "Highway"
        return initSpeed + 5 * 25
    else if roadType == "City"
        return initSpeed + 3 * 25
    else if roadType == "Off-road"
        return initSpeed + 1 * 25
    else: 
        return: "road type does not exist"


5.b examples
    if initSpeed = 5, roadType = Highway, output should be 205
    if initSpeed = 55, roadType = Off-road, output should be 130

5.c boundary conditions:
    when the road type is invalid
    when the initial speed is negative
*/
#include <iostream>

using namespace std;

int main(){
    double initSpeed;
    string roadType;

    cout << "Enter the initial speed:" << endl;
    cin >> initSpeed;

    cout << "Enter the road type:" << endl;
    cin >> roadType;

    if (initSpeed <= 0)
        cout << "invalid speed" << endl;
    else if (initSpeed < 20){
        if (roadType == "Highway"){
            cout << "The final velocity is " << initSpeed + 8 * 25 << " km/h";
        }
        else if (roadType == "City"){
            cout << "The final velocity is " << initSpeed + 5 * 25 << " km/h";
        }
        else if (roadType == "Off-road"){
            cout << "The final velocity is " << initSpeed + 2 * 25 << " km/h";
        }
        else
            cout << "road type does not exist" << endl;
    }
    else if (initSpeed < 60){
        if (roadType == "Highway")
            cout << "The final velocity is " << initSpeed + 10 * 25 << " km/h";
        else if (roadType == "City")
            cout << "The final velocity is " << initSpeed + 7 * 25 << " km/h";
        else if (roadType == "Off-road")
             cout << "The final velocity is " << initSpeed + 3 * 25 << " km/h";
        else
            cout << "road type does not exist" << endl;
    }
    else{
        if (roadType == "Highway")
            cout << "The final velocity is " << initSpeed + 5 * 25 << " km/h";
        else if (roadType == "City")
            cout << "The final velocity is " << initSpeed + 3 * 25 << " km/h";
        else if (roadType == "Off-road")
            cout << "The final velocity is " << initSpeed + 1 * 25 << " km/h";
        else
            cout << "road type does not exist" << endl;
    } 
        
}