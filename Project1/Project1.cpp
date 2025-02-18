#include <iostream>
#include <cassert>

using namespace std;

bool isValidBase(char base){
    if (base == 'A' || base == 'C' || base == 'G' || base == 'T'){
        return true;
    } else{
        return false;
    }
}

bool isValidStrand(string strand){
    bool flag = true;
    if (strand.empty()){
        return false;
    }else{
        for (unsigned int i = 0; i < strand.length(); i++){
            if (!isValidBase(strand[i])){
                flag = false;
            }
        }
    }
    return flag;
    flag = true;
}

double strandSimilarity(string strand1, string strand2){
    int count = 0;
    double compared = 0;
    if (strand1.length() == strand2.length()){
        for (unsigned int i = 0; i < strand1.length(); i++){
            if (strand1[i] == strand2[i]){
                count++;
            }
        }
        compared = (double)count / (double)strand1.length();
    }
    return compared;
}

int bestStrandMatch(string input_strand, string target_strand){
    int previousCounter = 0;
    int counter = 0;
    for (unsigned int i = 0; i < (input_strand.length() - target_strand.length()); i++){
        if (input_strand[i] == target_strand[0]){
            for (unsigned int j = 0; j < target_strand.length(); j++){
                if (input_strand[i+j] == target_strand[j]){
                    counter++;
                }
            }
            previousCounter = counter;
            counter = 0;
        }
    }
    return (double)previousCounter / (double)target_strand.length();
}

int main(){
    cout << bestStrandMatch("hello world!", "wors") << endl;
}
