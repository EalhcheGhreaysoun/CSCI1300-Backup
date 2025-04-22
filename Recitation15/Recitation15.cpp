/*
Psudocode:
define function Fibonacci
take input n
variable total = 1
variable prev_total = 0
for and integer i = 0 less than n:
x = total;
total = prev_total+x;
prev_total = x;
increment i
end
end

inputs:
n=3, total = 2
n=5, total = 5
n=8, total = 21
*/
#include <iostream>

using namespace std;

int Fibonacci(int n){
    int total = 1;
    int prev_total = 0;
    int x = 0;

    for (int i = 0; i < n-1; i++){
        x = total;
        total = prev_total+x;
        prev_total = x;
    }
    return total;
}
int main(){
    cout << Fibonacci(8) << endl;
    return 0;
}