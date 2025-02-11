#include <iostream>
#include <string>
#include <cassert> // added cassert to use the assert function
using namespace std;

bool passcodeMatchCheck(string passcode, string confirmPasscode) // changed return type
{
    return passcode == confirmPasscode;
}

int main()
{
   bool passcodeMatch = passcodeMatchCheck("2158","2158"); // added quotes around first argument to passcodeMatchCheck
   assert(passcodeMatch == true);
}