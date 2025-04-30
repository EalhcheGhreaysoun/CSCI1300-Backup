
#include "Board.h"

#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

using namespace std;

void Board::initializeBoard()
{
// Seed random number generator in your main function once
for (int i = 0; i < 2; i++)
{
    initializeTiles(i); // This ensures each lane has a unique tile distribution
}
}

void Board::initializeTiles(int path)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
        // Set the last tile as Orange for "Pride Rock"
        temp.color = 'O';
        }
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 -green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else{
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
            int color_choice = rand() % 5;
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
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[path][i] = temp;
    }
}

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
    _player_count = _MAX_PLAYERS;
    }
    else
    {
    _player_count = player_count;
    }
    // Initialize player position and path
    for (int i = 0; i < _player_count; i++)
    {
        _playerPosition[i].position = 0;
    }

    // Initialize tiles
    initializeBoard();
}

bool Board::isPlayerOnTile(PlayerPosition playerPosition,int path, int pos)
{
    if(playerPosition.path == path){
        if (playerPosition.position == pos)
        {
            return true;
        }
    }
    return false;
}
void Board::displayTile(int path, int pos)
{
    // string space = " ";
    string color = "";

    int player1 = isPlayerOnTile(_playerPosition[0], path, pos);
    int player2 = isPlayerOnTile(_playerPosition[1], path, pos);
    // Template for displaying a tile: <line filler space> <color start> |<playersymbol or blank space>| <reset color> <line filler space> <endl>
    // Determine color to display
    if (_tiles[path][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[path][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[path][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[path][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[path][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[path][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[path][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[path][pos].color == 'Y')
    {
        color = GREY;
    }
    if (player1 == true && player2 != true){
        cout << color << "|" << 1 << "|" << RESET;
    }else if(player1 != true && player2 == true){
        cout << color << "|" << 2 << "|" << RESET;
    }else if(player1 == true && player2 == true){
        cout << color << "|" << "1 & 2" << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int path)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(path, i);
    }
    cout << endl;
}
void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}
bool Board::movePlayer(int player_index, int m)
{
    // Increment player position
    _playerPosition[player_index].position += m;
    if (_playerPosition[player_index].position >= _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _playerPosition[player_index].position;
    }
    return -1;
}

int Board::getPlayerPath(int player_index) const
{
    return _playerPosition[player_index].path;
}

void Board::initPlayer(int index, string name, int age, int strength, int stamina, int wisdom, int pridePts)
{
    player[index].name = name;
    player[index].strength = strength;
    player[index].stamina = strength;
    player[index].wisdom = wisdom;
    player[index].pridePts = pridePts;
}

void Board::setPlayerValue(int player_index, string value, int attribute)
{
    switch (attribute)
    {
    case 0:
        player[player_index].name = value;
        break;
    case 1:
        player[player_index].age += stoi(value);
        break;
    case 2:
        player[player_index].strength += stoi(value);
        break;
    case 3:
        player[player_index].stamina += stoi(value);
        break;
    case 4:
        player[player_index].wisdom += stoi(value);
        break;
    case 5:
        player[player_index].pridePts += stoi(value);
        break;
    case 6:
        player[player_index].advisor += stoi(value);
        break;
    default:
        break;
    }
}

void Board::setPlayerPath(int player_index, int value)
{
    _playerPosition[player_index].path = value;
}


string Board::getPlayerName(int index){
    return player[index].name;
}
int Board::getPlayerAge(int index){
    return player[index].age;
}
int Board::getPlayerStrength(int index){
    return player[index].strength;
}
int Board::getPlayerStamina(int index){
    return player[index].stamina;
}
int Board::getPlayerWisdom(int index){
    return player[index].wisdom;
}
int Board::getPlayerPridePts(int index){
    return player[index].pridePts;
}
int Board::getPlayerAdvisor(int index){
    return player[index].advisor;
}

char Board::getTile(int path, int pos)
{
    return _tiles[path][pos].color;
}
