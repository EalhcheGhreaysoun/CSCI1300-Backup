
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int m = 0;
    int i = 0;

    while (i < 5)
    {
        int s = 1;
        if (i == 0 && (i % 3 == 0)){
            s = s * (-1);
            cout << m * s << endl;
        }else{
            m+= 2;
            cout << m << endl;
        }
        i++;
    }
}

//the code outputs 0, 2, 4, 6, 8.