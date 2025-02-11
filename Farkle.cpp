#include <iostream>
#include<array>
#include <cstdlib>
#include <ctime> 
using namespace std;

array<int,6> rollDice(int num){
    srand(time(0));
    array<int, 6> array;
    int input = num;
    for(int i = 1; i <= input; i++){
        array[i - 1] = rand() % 6 + 1;
    }
    return array;
}



int main(){
    rollDice(6);
    
}