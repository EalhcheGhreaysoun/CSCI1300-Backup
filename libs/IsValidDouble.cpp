#include <sstream>
using namespace std;

bool IsValidateDouble(string input){
    stringstream numS(input);
    string line;
    int beginningIdx = 0;
    bool aPeriod = false;
    bool isValidNum = true;
    while(getline(numS, line)){
        if(line[0] == '-'){
            beginningIdx = 1;
        }
        for(int i = beginningIdx; i < static_cast<int>(line.length()); i++){
            if(!aPeriod && line[i] == '.' && i != beginningIdx){
                aPeriod = true;
            }else if(aPeriod && line[i] == '.'){
                isValidNum = false;
            }else if(!isdigit(line[i])){
                isValidNum = false;
            }
        }
    }
    return isValidNum;
}