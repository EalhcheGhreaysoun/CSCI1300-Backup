#include <iostream>
#include <fstream>
#include <string>

//import previously made functions
#include "libs/IsValidDouble.cpp"
#include "libs/SplitString.cpp"

using namespace std;

int main()
{
    double midterm1Sum = 0;
    double midterm2Sum = 0;
    double midterm3Sum = 0;
    int numStudents = 0;
    int idx = 0;
    bool invalidString = false;
    int invalidStudent;

    double NumsIn[3];
    string NumsInS[3];

    ifstream fileIn("midterms.txt");
    if(fileIn.fail()){
        cout << "file failed" << endl;
    }
    string line;
    while(getline(fileIn, line)){
        SplitString(line, ',', NumsInS, 3);
        if(line != ""){
            numStudents++;
            idx = 0;
            while(idx < 3){
                if(IsValidateDouble(NumsInS[idx])){
                    NumsIn[idx] = stod(NumsInS[idx]);
                    switch (idx)
                    {
                    case 0:
                        midterm1Sum += NumsIn[idx];
                        break;
                    case 1:
                        midterm2Sum += NumsIn[idx];
                        break;
                    case 2:
                        midterm3Sum += NumsIn[idx];
                        break;
                    default:
                        break;
                    }
                }
                else if(!IsValidateDouble(NumsInS[idx])){
                    invalidString = true;
                    invalidStudent = numStudents;
                }
                idx++;
            }
            cout << numStudents;
        }
    }

    if(!invalidString){
        cout << "The average scores per midterm are: " << endl;
        cout << "Midterm 1: " << midterm1Sum/(numStudents) << endl;
        cout << "Midterm 2: " << midterm2Sum/(numStudents) << endl;
        cout << "Midterm 3: " << midterm3Sum/(numStudents) << endl;
    }else if(invalidString){
        cout << "Invalid value detected in Student " << invalidStudent << "'s score!" << endl;
    }
    return 0;
}