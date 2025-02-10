#include <iostream>
#include <string>
using namespace std;


bool checkDigit(string c){
    bool validate = true;
    const char *charArray = c.c_str();

    for (unsigned int i = 0; i < c.length(); i++){
        if(!isdigit(charArray[i])){
            if (charArray[0] == '-' && c.length() > 1){
                validate = true;
            }else{
                validate = false;
            }
        }
    }
    if (validate){
        return true;
    }else{
        return false;
    }
}

bool validateInt(string input){
    if (!input.empty() && checkDigit(input)){
        return true;
    }else{
        return false;
    }

}

int main(){
    string number;
    cout << "Enter the integer : " << endl;
    getline(cin, number);
    if(validateInt(number))
    {
        cout << "The entered string is a valid integer!!" << endl;
    }
    else if (!validateInt(number))
    {
        cout << "The entered string is not a valid integer!!" << endl;
    }
    return 0;
}