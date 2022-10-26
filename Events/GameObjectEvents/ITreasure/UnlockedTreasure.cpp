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
	this->notify(Message("log_game", "react from UnlockedTreasure\n"));
	std::cout << "Вы открыли сундук с " << gold << " золота!" << '\n';
	player->add_gold(gold);
}
