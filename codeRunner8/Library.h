#include <iostream>

using namespace std;

class Library{
public:
    Library();
    Library(string name);
    Library(string name, int page_counts[], int arr_size);
    string getName();
    int getCurrentBooks();
    void setName(string name);
    int getPageCount(int page);
    bool addPageCount(int pages);
    double getAveragePageCount();

private:
    string _name;
    const static int _MAX_BOOKS = 10;
    int _page_counts[_MAX_BOOKS];
    int _current_books = 0;
};
