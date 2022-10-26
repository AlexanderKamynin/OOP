#include "Trap.h"
#include <iostream>

void Trap::React()
{
	Message msg("log_game", "react from trap\n");
	this->notify(msg);
	std::cout << "���! �������..." << '\n';
	player->decrease_health(2);
}

bool Trap::is_one_time()
{
	return true;
}
