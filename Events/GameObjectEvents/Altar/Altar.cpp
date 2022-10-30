#include "Altar.h"

void Altar::React()
{
	Message msg(EnumClass::LOG_GAME, "Altar::React()");
	this->notify(msg);
	std::cout << "����� ���� ������ � �������� �����" << '\n';
	int player_health = player->get_health();
	int max_player_health = player->get_max_health();
	int full_heal_cost = cost_one_hp * (max_player_health - player_health);
	int half_heal_cost = cost_one_hp * (max_player_health - player_health) / 2;


	if (player_health == max_player_health) {
		std::cout << "�� ��������� �������..." << '\n';
	}
	else {
		std::cout << "� ��� " << player->get_gold() << " �����" << '\n';
		std::cout << "��������, ��� �� ������ ��������������... [1/2/3]" << '\n';
		std::cout << "\t1 - ������ ��������������(" << max_player_health - player_health
			<< " ��������): " << full_heal_cost << " �����" << '\n';
		std::cout << "\t2 - �������������� �� �������� (" 
			<< (max_player_health - player_health) / 2
			<< " ��������): " << half_heal_cost << " �����" << '\n';
		std::cout << "\t3 - ����" << '\n';
		std::string choice = "";
		while (choice != "1" and choice != "2" and choice != "3") {
			std::cin >> choice;
			if (choice == "1") {
				if (player->get_gold() >= full_heal_cost) {
					player->increase_health(max_player_health - player_health);
					player->take_gold(full_heal_cost);
				}
				else {
					std::cout << "�� ������� �����..." << '\n';
					break;
				}
			}
			else if (choice == "2") {
				if (player->get_gold() >= half_heal_cost) {
					player->increase_health((max_player_health - player_health) / 2);
					player->take_gold(half_heal_cost);
				}
				else {
					std::cout << "�� ������� �����..." << '\n';
					break;
				}
			}
			else if (choice == "3") {
				break;
			}
			else {
				Message msg(EnumClass::LOG_ERROR, "Altar::React(), incorrect input value");
				this->notify(msg);
				std::cout << "������� ����� 1, 2 ��� 3..." << '\n';
			}
		}
	}
}

bool Altar::is_one_time()
{
	return false;
}
