#include <iostream>
#include <cassert>
using namespace std;

bool idLengthCheck(int ID) 
{
    if (ID >= 999 && ID < 10000) // changed || to &&
    {
        return true;
    }
    return false;
}

int main()
{
    assert(idLengthCheck(12345678));
    assert(idLengthCheck(123456789) == false); // removed quotes from agrument to idLengthCheck, changed False to false
    return 0;
}

