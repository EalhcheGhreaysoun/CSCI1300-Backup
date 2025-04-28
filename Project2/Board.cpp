#include "Board.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>

using namespace std;


void Board::initializeBoard(int path)
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(path);  // This ensures each lane has a unique tile distribution
    }
}

void Board::initializeTiles(int path)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    int i;

    srand(time(0));
    if(path == 1){
        // Keep track of green tile positions to ensure we place exactly 30 greens
        for (i = 0; i < total_tiles; i++)
        {
            
            if (i == total_tiles - 1) {
                // Set the last tile as Orange for "Pride Rock"
                temp.color = 'O';
            } 
            else if (i == 0) {
                // Set the last tile as Orange for "Pride Rock"
                temp.color = 'Y';
            } 
            else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
                temp.color = 'G';
                green_count++;
            }
            else
            {
                // Randomly assign one of the other colors: Blue(good), Pink (good), Brown(bad), Red (bad), Purple (challenge tile)
                int color_choice = (rand()%7);
                if(green_count < 15){
                    switch (color_choice)
                    {
                        case 0:
                            temp.color = 'B'; // Blue
                            break;
                        case 1:
                            temp.color = 'P'; // Pink
                            break;
                        case 2:
                            temp.color = 'N'; // Brown
                            break;
                        case 3:
                            temp.color = 'N'; // Brown
                            break;
                        case 4:
                            temp.color = 'R'; // Red
                            break;
                        case 5:
                            temp.color = 'R'; // Red
                            break;
                        case 6:
                            temp.color = 'U'; // Purple
                            break;
                    }
                }
                else{
                    switch (color_choice)
                    {
                    case 0:
                            temp.color = 'B'; // Blue
                            break;
                        case 1:
                            temp.color = 'P'; // Pink
                            break;
                        case 2:
                            temp.color = 'B'; // Brown
                            break;
                        case 3:
                            temp.color = 'N'; // Brown
                            break;
                        case 4:
                            temp.color = 'R'; // Red
                            break;
                        case 5:
                            temp.color = 'U'; // Red
                            break;
                        case 6:
                            temp.color = 'U'; // Purple
                            break;
                    }
                }
            }
            // Assign the tile to the board for the specified lane
            _tiles[i] = temp;
        }
    }
    if(path == 2){
        for (i = 0; i < total_tiles; i++)
        {
            
            if (i == total_tiles - 1) {
                // Set the last tile as Orange for "Pride Rock"
                temp.color = 'O';
            } 
            else if (i == 0) {
                // Set the last tile as Orange for "Pride Rock"
                temp.color = 'Y';
            } 
            else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
                temp.color = 'G';
                green_count++;
            }
            else
            {
                // Randomly assign one of the other colors: Blue(good), Pink (good), Brown(bad), Red (bad), Purple (challenge tile)
                int color_choice = (rand()%7);
                if(green_count < 15){
                    switch (color_choice)
                    {
                        case 0:
                            temp.color = 'B'; // Blue B
                            break;
                        case 1:
                            temp.color = 'P'; // Pink P
                            break;
                        case 2:
                            temp.color = 'N'; // Brown N
                            break;
                        case 3:
                            temp.color = 'N'; // Brown N
                            break;
                        case 4:
                            temp.color = 'R'; // Red R
                            break;
                        case 5:
                            temp.color = 'R'; // Red R
                            break;
                        case 6:
                            temp.color = 'U'; // Purple U
                            break;
                    }
                }
                else{
                    switch (color_choice)
                    {
                    case 0:
                            temp.color = 'B'; // Blue
                            break;
                        case 1:
                            temp.color = 'P'; // Pink
                            break;
                        case 2:
                            temp.color = 'B'; // Brown
                            break;
                        case 3:
                            temp.color = 'N'; // Brown
                            break;
                        case 4:
                            temp.color = 'R'; // Red
                            break;
                        case 5:
                            temp.color = 'U'; // Red
                            break;
                        case 6:
                            temp.color = 'U'; // Purple
                            break;
                    }
                }
            }
            // Assign the tile to the board for the specified lane
            _tiles[i] = temp;
        }
    }
}

Board::Board()
{
   // Initialize player position
   _player_position = 0;

   // Initialize tiles
   initializeTiles(1); //temp
}

Board::Board(int path, int player_index)
{
    
    _player_position = 0;
    _player_index = player_index;
    // Initialize tiles
    initializeBoard(path);
}

bool Board::isPlayerOnTile(int pos)
{
    if (_player_position == pos)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int pos)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    
    if (_tiles[pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[pos].color == 'Y')
    {
        color = GREY;
    }
     if (player == true)
    {
        cout << color << "|" << (_player_index) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack()
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << endl;
}

void Board::displayBoard(int player_index)
{
    displayTrack();
}

void Board::setPlayerIndex(int index)
{
    _player_index = index;
}

bool Board::movePlayer(int n)
{   
    if(n < 0){
        if((_player_position + n) > 0){
            _player_position += n;
        }else{
            _player_position = 0;
        }
    }else{
        // Increment player position
        _player_position += n;
    }
    
    if (_player_position >= _BOARD_SIZE){
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition() const
{
    return _player_position;
}

char Board::getTile(int pos) const{
    return _tiles[pos].color;
}