#include "ExitEvent.h"

void ExitEvent::React()
{
	if (show_exit == false) {
		this->show_exit = true;
		if (boss_defeat) {
			this->activate = true;
			std::cout << "Вы нашли выход..." << '\n';
			std::cout << "Поздравляем! Вы победили :)" << '\n';
		}
		else {
			std::cout << "Вы открыли местоположение выхода. Победите босса, чтобы открыть выход..." << '\n';
		}
	}
	else if (boss_defeat) {
		this->activate = true;
		std::cout << "Поздравляем! Вы победили :)" << '\n';
	}
	else {
		std::cout << "Босс еще не побежден..." << '\n';
	}
}

bool ExitEvent::is_activate()
{
	return this->activate;
}

bool ExitEvent::is_show()
{
	return this->show_exit;
}

void ExitEvent::boss_is_defeat()
{
	boss_defeat = true;
}
