#ifndef BOARD_H
#define BOARD_H
#include "game.h"
#include "Tile.h"
class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    PlayerPosition _playerPosition[_MAX_PLAYERS];
    void displayTile(int path, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(PlayerPosition playerPosition,int path, int pos);

    

public:
    Player player[_MAX_PLAYERS];

    Board();
    Board(int player_count);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index, int m);
    int getPlayerPosition(int player_index) const;
    int getPlayerPath(int player_index) const;

    void initPlayer(int index, string name, int age, int strength, int stamina, int wisdom, int pridePts);

    void setPlayerValue(int player_index, string value, int attribute);
    void setPlayerPath(int player_index, int value);

    string getPlayerName(int index);
    int getPlayerAge(int index);
    int getPlayerStrength(int index);
    int getPlayerStamina(int index);
    int getPlayerWisdom(int index);
    int getPlayerPridePts(int index);
    int getPlayerAdvisor(int index);

    char getTile(int path, int pos);
};
#endif
