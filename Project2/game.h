#include "Board.h"
#include <iostream>

using namespace std;

class Player{
private:
    string _name;
    int _age;
    int _strength;
    int _stamina;
    int _wisdom;
    int _pridePts;

    int _advisor;

    Board _board;
public:
    Player();
    Player(string name, int age, int strength, int stamina, int wisdom, int pridePts);
    string getPlayerName() const;
    int getPlayerAge() const;
    int getPlayerStrength() const;
    int getPlayerStamina() const;
    int getPlayerWisdom() const;
    int getPlayerPridePts() const;
    void playerDisplayBoard();
    bool playerMovePlayer(int n);
    int playerGetPlayerPos();
    char playerGetTile(int pos) const;
    int getAdvisor() const;

    void setAdvisor(int advisor);
    void setBoard(Board board);
    void setPridePts(int delta);
    void setPlayerStrength(int n);
    void setPlayerStamina(int n);
    void setPlayerWisdom(int n);
};

class Advisor{

};