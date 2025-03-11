#include <sstream>

using namespace std;

int SplitString(string input_string, char separator, string arr[], const int ARR_SIZE){
    stringstream s(input_string);
    string token;
    int idx = 0;
    while(getline(s, token, separator)){
        if(idx < ARR_SIZE){
            arr[idx] = token;
        }else if(idx >= ARR_SIZE){
            return -1;
        }
        idx++;
    }
    return ARR_SIZE;
}