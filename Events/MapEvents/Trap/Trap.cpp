#include "Trap.h"
#include <iostream>

void Trap::React()
{
	std::cout << "���! �������..." << '\n';
	player->decrease_health(2);
}

bool Trap::is_one_time()
{
	return true;
}
