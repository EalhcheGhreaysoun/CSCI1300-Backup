#include <sstream>
using namespace std;

int split( string input_string, char separator, string arr[], const int ARR_SIZE )
{
    stringstream s(input_string);
    string token;
    int counter = 0;
    while(getline(s, token, separator)){
        counter++;
    }
    stringstream z(input_string);
    for(int i = 0; i < ARR_SIZE; i++){
        if(getline(z, token, separator)){
            arr[i] = token;
        }
    }
    if(counter > ARR_SIZE){
        return -1;
    }
    return counter;
}