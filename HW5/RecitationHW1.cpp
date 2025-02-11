#include <iostream>
#include <cassert> // added cassert to let us use the assert function

using namespace std;

double findMean(int a, int b, int c)
{
    int mean = (a+b+c) / 3; // add semicolon, parenthesis
    return mean;
}

int main()
{
    double average = findMean(2,5,2); // used the correct function
    assert(average == 3);
    return 0;
}

