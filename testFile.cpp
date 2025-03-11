#include <iostream>
#include <fstream>
#include "libs/SplitString.cpp"

using namespace std;

void printHikeStats(string file_name){
    ifstream hikeData(file_name);
    if (hikeData.fail()){
        cout << "Could not open file." << endl;
    }
    string tokenY;
    string tokenX;
    string name[30];
    string hikeLengthS[30];
    int hikeLength[30];
    string elevationGainS[30];
    int elevationGain[30];
    int idx = 0;
    int idy = 0;

    //get data into seperate arrays
    while(getline(hikeData, tokenY)){
        if(tokenY != ""){
            stringstream textX(tokenY);
            while(getline(textX, tokenX, '|')){
                if(idx == 0){
                    name[idy] = tokenX;
                }else if(idx == 1){
                    hikeLengthS[idy] = tokenX;
                }else if(idx == 2){
                    elevationGainS[idy] = tokenX;
                }
                idx++;
                cout << idy << " " << tokenX << endl;
            }
        }
        idx = 0;
        idy++;   
    }

    for(int i = 0; i < 30; i++){
        if(hikeLengthS[i] != ""){
            hikeLength[i] = stoi(hikeLengthS[i]);
            elevationGain[i] = stoi(elevationGainS[i]);
        }
    }

    for(int i = 0; i < 30; i++){
        cout << elevationGainS[i] << endl;
        
    }
    hikeData.close();
}

int main(){
    printHikeStats("testFile.txt");
    return 0;
}