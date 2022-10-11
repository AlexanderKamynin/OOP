#include "EnemiesEvents.h"

EnemiesEvents::EnemiesEvents(Player* player)
{
	this->player = player;
	this->gold = 0;
	this->damage = 0;
	this->health = 1;
	this->passkey = 0;
}

void EnemiesEvents::preview_battle() {
    std::cout << "Сразиться? [yes/no]" << '\n';
    std::string agree = "";
    while (agree != "yes" and agree != "no") {
        std::cin >> agree;
        if (agree == "yes") {
            battle();
        }
        else if (agree == "no") {
            int chance_to_escape = rand() % 11;
            if (chance_to_escape < 5) {
                std::cout << "Все же вас заметили..." << '\n';
                battle();
            }
            else {
                std::cout << "Вы избежали столкновения..." << '\n';
            }
        }
        else {
            std::cout << "Введите yes или no..." << '\n';
        }
    }
}

void EnemiesEvents::battle() {
    int player_damage = player->get_player_attack();
    int player_health = player->get_health();
    bool player_is_win = true;
    while (player_health > 0 and this->health > 0) {
        player_health = player->get_health();
        int chance_to_attack = rand() % 11;
        if (chance_to_attack >= 5) {
            this->health -= player_damage;
            if (is_dead()) {
                break;
            }
            else {
                player->decrease_health(this->damage);
                if (player->is_dead()) {
                    player_is_win = false;
                    break;
                }
            }
        }
        else 
        {
            player->decrease_health(this->damage);
            if (player->is_dead()) {
                player_is_win = false;
                break;
            }
            this->health -= player_damage;
        }
    }

    before_battle(player_is_win);
}

bool EnemiesEvents::is_dead() {
    if (this->health <= 0) {
        return true;
    }
    return false;
}

void EnemiesEvents::before_battle(bool battle_result) {
    if (battle_result) {
        std::cout << "Вы победили!";
        if (this->gold > 0) {
            player->add_gold(this->gold);
            std::cout << " Вы получили " << this->gold << " золота.";
        }
        if (this->passkey > 0) {
            player->add_passkey(this->passkey);
            std::cout << " Вы нашли " << this->passkey << " отмычек.";
        }
        std::cout << '\n';
    }
    else {
        std::cout << "Вы проиграли :(";
    }
}