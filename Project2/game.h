#include <iostream>

using namespace std;

class Player{
private:
    int _player_index;

    string _name;
    int _strength;
    int _stamina;
    int _wisdom;
    int _pridePts;
public:
    Player();
    Player(int index, string name, int strength, int stamina, int wisdom, int pridePts);
    int getPlayerIndex();
    string getPlayerName() const;
    int getPlayerStrength() const;
    int getPlayerStamina() const;
    int getPlayerWisdom() const;
    int getPlayerPridePts() const;
};

class Advisor{

};