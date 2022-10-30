#include "Altar.h"

void Altar::React()
{
	Message msg(EnumClass::LOG_GAME, "Altar::React()");
	this->notify(msg);
	std::cout << "Перед вами алтарь с целебной водой" << '\n';
	int player_health = player->get_health();
	int max_player_health = player->get_max_health();
	int full_heal_cost = cost_one_hp * (max_player_health - player_health);
	int half_heal_cost = cost_one_hp * (max_player_health - player_health) / 2;


	if (player_health == max_player_health) {
		std::cout << "Вы полностью здоровы..." << '\n';
	}
	else {
		std::cout << "У вас " << player->get_gold() << " монет" << '\n';
		std::cout << "Выберите, как вы хотите восстановиться... [1/2/3]" << '\n';
		std::cout << "\t1 - полное восстановление(" << max_player_health - player_health
			<< " здоровья): " << full_heal_cost << " монет" << '\n';
		std::cout << "\t2 - восстановиться на половину (" 
			<< (max_player_health - player_health) / 2
			<< " здоровья): " << half_heal_cost << " монет" << '\n';
		std::cout << "\t3 - уйти" << '\n';
		std::string choice = "";
		while (choice != "1" and choice != "2" and choice != "3") {
			std::cin >> choice;
			if (choice == "1") {
				if (player->get_gold() >= full_heal_cost) {
					player->increase_health(max_player_health - player_health);
					player->take_gold(full_heal_cost);
				}
				else {
					std::cout << "Не хватает монет..." << '\n';
					break;
				}
			}
			else if (choice == "2") {
				if (player->get_gold() >= half_heal_cost) {
					player->increase_health((max_player_health - player_health) / 2);
					player->take_gold(half_heal_cost);
				}
				else {
					std::cout << "Не хватает монет..." << '\n';
					break;
				}
			}
			else if (choice == "3") {
				break;
			}
			else {
				Message msg(EnumClass::LOG_ERROR, "Altar::React(), incorrect input value");
				this->notify(msg);
				std::cout << "Введите число 1, 2 или 3..." << '\n';
			}
		}
	}
}

bool Altar::is_one_time()
{
	return false;
}
