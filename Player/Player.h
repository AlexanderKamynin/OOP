#pragma once


class Player {
public:
    Player();

    void player_damage(int damage);

    ~Player() = default;
private:
    int gold;
    int hp;
    int attack;
    int lvl;
    int xp;
};