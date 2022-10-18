#include "UnlockedTreasure.h"

void UnlockedTreasure::set_gold_in_treasure(int gold)
{
	this->gold = gold;
}

void UnlockedTreasure::React()
{
	std::cout << "Вы открыли сундук с " << gold << " золота!" << '\n';
	player->add_gold(gold);
}
