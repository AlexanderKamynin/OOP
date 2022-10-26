#include "Boss.h"

void Boss::React()
{
	Message msg("log_game", "react from boss\n");
	this->notify(msg);
	std::cout << "ѕеред вами крупное существо, похоже это босс..." << '\n';
	preview_battle();
	if (is_dead()) {
		std::cout << "Ќайдите местоположение выхода..." << '\n';
	}
}

bool Boss::is_one_time()
{
	return this->is_dead();
}