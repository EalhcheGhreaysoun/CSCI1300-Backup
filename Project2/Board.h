#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[_BOARD_SIZE];
    int _player_position;
    int _player_index;
    void displayTile(int pos);
    void initializeTiles(int path);
    bool isPlayerOnTile(int pos);

public:
    Board();
    Board(int path, int player_index);
    void displayTrack();
    void initializeBoard(int path);
    void displayBoard(int player_index);
    void setPlayerIndex(int index);
    bool movePlayer(int n);
    int getPlayerPosition() const;
    char getTile(int pos) const;
};

#endif