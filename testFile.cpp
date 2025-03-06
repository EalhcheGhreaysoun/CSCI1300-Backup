#include <iostream>

using namespace std;

int minAverg( int scores[][10], const int NUM_STUDENTS, double threshold )
{
    double sum = 0;
    double mean = 0;
    double worstStudent = 0;
    bool isNoWorstStudent = true;

    for(int i = 0; i < NUM_STUDENTS; i++){
        for (int j = 0; j < 10; j++){
            sum += scores[i][j];
        }
        mean = sum/10;
        if(mean <= threshold){
            worstStudent = i;
            isNoWorstStudent = false;
            break;
        }
        sum = 0;
    }
    if(isNoWorstStudent){
        return -1;
    }
    else{return worstStudent;}
}

int main(){
    int scores[4][10] = {
        {50, 60, 55, 65, 70, 60, 58, 62, 55, 65}, 
        {70, 80, 75, 85, 90, 65, 78, 82, 88, 74},
        {10, 20, 15, 25, 12, 30, 18, 22, 17, 15},  
        {100, 110, 105, 115, 120, 90, 108, 102, 114, 104},
    };
    cout << "returned student index: " <<  minAverg(scores, 5, 40);
    return 0;
}
