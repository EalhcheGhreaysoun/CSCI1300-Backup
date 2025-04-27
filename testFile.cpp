
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    //char input;
    string line;
    string element = "";

    

    ifstream characters("testFile.txt");

    
    cout << "Player 1:" << endl;
    cout << "Choose a character out of the following list." << endl;
    while(getline(characters, line)){
        stringstream ss(line);
        cout << line << endl;
        while (getline(ss, element, '|')){
            cout << element << " ";
        }
        cout << endl;
    }
    
}