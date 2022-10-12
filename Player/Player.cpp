#include "Player.h"

Player::Player() {
    this->hp = 100;
    this->attack = 10;
    this->gold = 0;
    this->step = 0;
    this->passkey = 0;
}

int Player::get_player_attack()
{
    return this->attack;
}

void Player::decrease_health(int damage) {
    this->hp -= damage;
}

int Player::get_health()
{
    return this->hp;
}

int Player::get_step()
{
    return this->step;
}

void Player::increase_step()
{
    this->step++;
}

int Player::get_gold()
{
    return this->gold;
}

void Player::add_gold(int gold)
{
    this->gold += gold;
}

int Player::get_passkey()
{
    return this->passkey;
}

void Player::add_passkey(int passkey)
{
    this->passkey += passkey;
}

void Player::take_passkey()
{
    this->passkey -= 1;
}

bool Player::is_dead()
{
    if (this->hp <= 0) {
        return true;
    }
    return false;
}