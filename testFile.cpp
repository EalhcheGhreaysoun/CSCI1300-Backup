#include <iostream>
using namespace std;

double calculateSowingTime(double area, char machine_type){
    if (area > 0)
    {
        switch (machine_type)
        {
            case 'W':
                return (3/2)*area;
                break;
            case 'X':
                return (10/3)*area;
                break;
            case 'Y':
                return (7/2)*area;
                break;
            case 'Z':
                return (8/7)*area;
                break;
            default:
                return 0;
                break;
        }
    }else {
        return 0;
    }
}

int main(){
    double areaIn;
    char machine;

    cout << "Enter area of the farmland in sq ft:" << endl;
    cin >> areaIn;

    cout << "Enter the type of sowing machine to be used:" << endl;
    cin >> machine;

    if (calculateSowingTime(areaIn, machine) == 0)
    {
        cout << "Area or machine type is invalid. Time cannot be calculated." << endl;            
    }else {
        cout << "The time taken is: " << calculateSowingTime(areaIn, machine) << "minutes." << endl;
    }
    
}