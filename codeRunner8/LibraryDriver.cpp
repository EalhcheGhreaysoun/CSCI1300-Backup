#include <iostream>
#include "Library.h"

using namespace std;

void findLibraryWithLargestAveragePageCount(Library library[], const int library_size){
    int largest = 0;
    for (int i = 0; i < library_size; i++){
        if (library[largest].getAveragePageCount() < library[i].getAveragePageCount()){
            largest = i;
        }
    }
    cout << library[largest].getName() << endl;
}

int main(){	
    const int ARR_SIZE = 3;
    int page_count1[3] = {10, 20, 30};
    int page_count2[4] = {10, 20, 30, 40};
    int page_count3[4] = {20, 40, 10, 10};
    Library library_1 = Library("CS1300 Library", page_count1, 3);
    Library library_2 = Library("Elise's Library", page_count2, 4);
    Library library_3 = Library("Pawin's Library", page_count3, 4);
    Library libraries[ARR_SIZE] = {library_1, library_2, library_3};
    cout << "test" << endl;
    //cout << findLibraryWithLargestAveragePageCount(libraries, ARR_SIZE) << endl;
    findLibraryWithLargestAveragePageCount(libraries, ARR_SIZE);
}