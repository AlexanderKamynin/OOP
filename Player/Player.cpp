#include "Player.h"

Player::Player() {
    this->max_hp = 100;
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

void Player::increase_health(int health_to_add)
{
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::increase_health(), health to add: " + std::to_string(health_to_add));
    this->notify(msg);
    this->hp += health_to_add;
}

void Player::decrease_health(int damage) {
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::decrease_health(), damage value: " + std::to_string(damage));
    this->notify(msg);
    this->hp -= damage;
}

int Player::get_max_health()
{
    return this->max_hp;
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
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::increase_step()");
    this->notify(msg);
    this->step++;
}

int Player::get_gold()
{
    return this->gold;
}

void Player::add_gold(int gold)
{
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::add_gold(), gold to add: " + std::to_string(gold));
    this->notify(msg);
    this->gold += gold;
}

void Player::take_gold(int gold)
{
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::take_gold(), gold to take: " + std::to_string(gold));
    this->notify(msg);
    this->gold -= gold;
}

int Player::get_passkey()
{
    return this->passkey;
}

void Player::add_passkey(int passkey)
{
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::add_passkey(), passkey to add: " + std::to_string(passkey));
    this->notify(msg);
    this->passkey += passkey;
}

void Player::take_passkey()
{
    Message msg(EnumClass::LogLevels::LOG_GAME, "Player::take_passkey()");
    this->notify(msg);
    this->passkey -= 1;
}

bool Player::is_dead()
{
    if (this->hp <= 0) {
        return true;
    }
    return false;
}