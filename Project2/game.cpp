#include "game.h"
#include "Board.h"
#include <iostream>

using namespace std;

Player::Player(){

}

Player::Player(string name, int age, int strength, int stamina, int wisdom, int pridePts){
   _name = name;
   _age = age;
   _strength = strength;
   _stamina = stamina;
   _wisdom = wisdom;
   _pridePts = pridePts;
}

string Player::getPlayerName() const
{
    return _name;
}

int Player::getPlayerAge() const {
    return _age;
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

void Player::playerDisplayBoard()
{
    _board.displayTrack();
}

bool Player::playerMovePlayer(int n)
{
    return _board.movePlayer(n);
}


void Player::setAdvisor(int advisor)
{
    _advisor = advisor;
}

int Player::playerGetPlayerPos()
{
    return _board.getPlayerPosition();
}

char Player::playerGetTile(int pos) const
{
    return _board.getTile(pos);
}

int Player::getAdvisor() const
{
    return _advisor;
}

void Player::setBoard(Board board)
{
    _board = board;
}

void Player::setPridePts(int delta)
{
    _pridePts += delta;
}

void Player::setPlayerStrength(int n)
{
    _strength += n;
}

void Player::setPlayerStamina(int n)
{
    _stamina += n;
}

void Player::setPlayerWisdom(int n)
{
    _wisdom += n;
}
