#include "UnlockedTreasure.h"

void UnlockedTreasure::set_gold_in_treasure(int gold)
{
	this->gold = gold;
}

void UnlockedTreasure::React()
{
	std::cout << "�� ������� ������ � " << gold << " ������!" << '\n';
	player->add_gold(gold);
}
