#include "Trap.h"
#include <iostream>

void Trap::React()
{
	std::cout << "Óïñ! Ëîâóøêà..." << '\n';
	player->player_damage(1);
}
