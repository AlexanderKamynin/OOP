#include "Trap.h"
#include <iostream>

void Trap::React()
{
	Message msg(EnumClass::LOG_GAME, "Trap::React()");
	this->notify(msg);
	std::cout << "Óïñ! Ëîâóøêà..." << '\n';
	player->decrease_health(2);
}

bool Trap::is_one_time()
{
	return true;
}
