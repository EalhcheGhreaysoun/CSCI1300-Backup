#include <iostream> 
using namespace std;

int main() {

  int num = 1; 

  while(num <= 10) {
    cout << num << " ";
    num = num + 1;     // removed the int before num
  } 

  return 0; 
} 