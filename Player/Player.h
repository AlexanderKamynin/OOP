#pragma once

class Player {
public:
    Player();

    int player_attack();

    void decrease_health(int damage);

    int get_health();

    int get_step();

    void increase_step();

    int get_gold();

    void add_gold(int gold);

    int get_passkey();

    void add_passkey();

    void take_passkey();

    ~Player() = default;
private:
    int gold;
    int hp;
    int attack;
    int step;
    int passkey; //отмычки
};