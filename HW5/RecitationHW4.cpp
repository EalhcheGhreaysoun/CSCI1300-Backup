#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool passwordMatchCheck(string, string); // changed char, char to string, string
bool idLengthCheck(char);

int main() {
    int ID;
    string password;
    string confirmPassword;

    cout << "Enter your member ID: ";
    cin >> ID;
    assert(idLengthCheck(ID));
    
    cout << "Enter your password: ";
    cin >> password;

    cout << "Confirm your password: ";
    cin >> confirmPassword;

    if (passwordMatchCheck(password, confirmPassword)) 
    {
        cout << "Password set successfully for " << ID << "." << endl; // change username to variable ID
    } 
    else if (!passwordMatchCheck(password, confirmPassword)) 
    {
        cout << "Passwords do not match." << endl;
    } 
    else if(!idLengthCheck(ID)) 
    {
        cout << "ID is invalid." << endl;
    }

    return 0;
}

bool passwordMatchCheck(string password, string confirmPassword)
{
    // appropriate definitions
}

bool idLengthCheck(string password)
{
    // appropriate definitions
}