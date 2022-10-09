#include "Player.h"

Player::Player() {
    this->hp = 100;
    this->attack = 10;
    this->gold = 0;
}

void Player::player_damage(int damage) {
    this->hp = this->hp - damage;
}

int Player::get_health()
{
    return this->hp;
}
