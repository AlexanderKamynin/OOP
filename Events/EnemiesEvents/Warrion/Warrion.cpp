#include "Warrion.h"

void Warrion::React()
{
	Message msg("log_game", "react from warrion\n");
	this->notify(msg);
	std::cout << "Вы натолкнулись на воина..." << '\n';
	preview_battle();
}

bool Warrion::is_one_time()
{
	return this->is_dead();
}