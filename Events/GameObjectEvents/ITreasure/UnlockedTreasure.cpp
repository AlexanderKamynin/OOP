#include "UnlockedTreasure.h"

bool UnlockedTreasure::is_one_time()
{
	return true;
}

void UnlockedTreasure::set_gold_in_treasure(int gold)
{
	this->gold = gold;
}

void UnlockedTreasure::React()
{
	Message msg("log_game", "react from UnlockedTreasure\n");
	this->notify(msg);
	std::cout << "Вы открыли сундук с " << gold << " золота!" << '\n';
	player->add_gold(gold);
}
