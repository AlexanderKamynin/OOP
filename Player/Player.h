#pragma once

class Player {
public:
    Player();

    void player_damage(int damage);

    int get_health();

    ~Player() = default;
private:
    int gold;
    int hp;
    int attack;
};