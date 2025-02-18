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

int main(){
    
    assert(strandSimilarity("AGGT" , "CTGA") == 0.25);
    assert(strandSimilarity("CCTT" , "CCTT") == 1);
    assert(strandSimilarity("ATG" , "AAATTT") == 0);
    assert(strandSimilarity("CTGTAGAGCT" , "TAGCTACCAT") == 0.2);
}
