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
    int dice[6];
    int keptDice[6];
    int input;
    int possibleKeptDice[6];
    int possibleKeptDiceNum = 0;

    for(int i = 0; i < 6; i++){
        dice[i] = rollDice(6)[i];
    }
    
    cout << dice[0] << dice[1] << dice[2] << dice[3] << dice[4] << dice[5] << endl;

    for(int i = 0; i < 6; i++){
        if(dice[i] == 5){
            possibleKeptDice[i] = dice[i];
            possibleKeptDiceNum++;

            continue;
        } else if(dice[i] == 1){
            possibleKeptDice[i] = dice[i];
            possibleKeptDiceNum++;
            continue;
        }else{
            possibleKeptDice[i] = 0;
        }
    }



    int i = 0;
    while(i < possibleKeptDiceNum){
        cout << "say kept dice " << i + 1 << endl;
        cin >> input;
        if(possibleKeptDice[input - 1] == 0){
            cout << "you cant keep this die" << endl;
            continue;
        }else {
            keptDice[i] = dice[input - 1];
            cout << keptDice[i] << endl;
            i++;
            continue;
        }
    }
}