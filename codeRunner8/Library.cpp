#include "Library.h"

Library::Library()
{
    _name = "";
    _current_books = 0;
    for(int i = 0; i < _MAX_BOOKS; i++){
        _page_counts[i] = 0;
    }
}

Library::Library(string name)
{
    _name = name;
    _current_books = 0;
    for(int i = 0; i < _MAX_BOOKS; i++){
        _page_counts[i] = 0;
    }
}

Library::Library(string name, int page_counts[], int arr_size)
{
    _name = name;
    if (arr_size <= _MAX_BOOKS){
        _current_books = arr_size;
    }else{
        _current_books = _MAX_BOOKS;
    }
    for(int i = 0; i < _current_books; i++){
        _page_counts[i-1] = page_counts[i];
    }

}

string Library::getName()
{
    return _name;
}

int Library::getCurrentBooks()
{
    return _current_books;
}

void Library::setName(string name)
{
    _name = name;
}

int Library::getPageCount(int page)
{
    if(page < _current_books){
        return _page_counts[page-1];
    }else{
        return -1;
    }
}

bool Library::addPageCount(int pages)
{
    if(_current_books >= _MAX_BOOKS){
        return false;
    }else{
        if(pages > 0){
            _page_counts[_current_books-1] = pages;
            _current_books+=1;
            return true;
        }else{
            return false;
        }
    }
}

double Library::getAveragePageCount()
{
    double total = 0;
    if(_current_books == 0){
        return 0;
    }
    else{
        for (int i = 0; i < _current_books; i++){
            total += _page_counts[i-1];
        }
        return total/(double)_current_books;
    }
}
