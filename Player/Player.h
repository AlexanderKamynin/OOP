#pragma once

class Player {
public:
    Player();

    int get_player_attack();

    void increase_health(int health_to_add);

    void decrease_health(int damage);

    int get_max_health();

    int get_health();

    int get_step();

    void increase_step();

    int get_gold();

    void add_gold(int gold);

    void take_gold(int gold);

    int get_passkey();

    void add_passkey(int passkey);

    void take_passkey();

    bool is_dead();

    ~Player() = default;
private:
    int max_hp;
    int gold;
    int hp;
    int attack;
    int step;
    int passkey;
};