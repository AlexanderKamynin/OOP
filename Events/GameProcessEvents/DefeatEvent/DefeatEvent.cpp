#include "DefeatEvent.h"
#include <iostream>


void DefeatEvent::React()
{
	if (player->is_dead()) {
		this->activate = true;
		std::cout << "Игра окончена. Вы погибли..." << '\n';
	}
}

bool DefeatEvent::is_one_time()
{
	return false;
}

bool DefeatEvent::is_activate()
{
	return this->activate;
}
