#include <iostream>
#include <string>
using namespace std;

double strandSimilarity(string strand1, string strand2){
    int count = 0;
    double compared = 0;
    if (strand1.length() == strand2.length()){
        for (unsigned int i = 0; i < strand1.length(); i++){
            if (strand1[i] == strand2[i]){
                count++;
            }
        }
        compared = (double)count / (double)strand2.length();
    }
    return compared;
}

int main()
{
    cout << strandSimilarity("ASDFG", "ASDFF") << endl;
}
