// This program implements XOR
#include <iostream> // missing <>
using namespace std;

//Set the variable value to 1 when x or y is 1
int main()
{
int x=1,y=0,value;
if (x==1){
    if(y==0)
    value = 1;

    else
        value = 0;
}
if(x==0){
    if(y==0){
        value = 0;
    }
        
    else
        value = 1;

    }   

cout << value << endl; // missing <
return 0;

}