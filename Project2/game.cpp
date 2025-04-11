#include "game.h"
#include <iostream>

using namespace std;

Player::Player(){

}

Player::Player(int index, string name, int strength, int stamina, int wisdom, int pridePts){
    _player_index = index;
   _name = name;
   _strength = strength;
   _stamina = stamina;
   _wisdom = wisdom;
   _pridePts = pridePts;
}

int Player::getPlayerIndex()
{
    return _player_index;
}

string Player::getPlayerName() const
{
    return _name;
}

int Player::getPlayerStrength() const
{
    return _strength;
}

int Player::getPlayerStamina() const
{
    return _stamina;
}

int Player::getPlayerWisdom() const
{
    return _wisdom;
}

int Player::getPlayerPridePts() const
{
    return _pridePts;
}