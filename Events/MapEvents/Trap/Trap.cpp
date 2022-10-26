#include "Trap.h"
#include <iostream>

void Trap::React()
{
	this->notify(Message("log_game", "react from trap\n"));
	std::cout << "Óïñ! Ëîâóøêà..." << '\n';
	player->decrease_health(2);
}

bool Trap::is_one_time()
{
	return true;
}
