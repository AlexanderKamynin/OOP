#include "Trap.h"
#include <iostream>

void Trap::React()
{
	std::cout << "���! �������..." << '\n';
	player->player_damage(1);
}
