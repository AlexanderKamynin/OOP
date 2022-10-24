#include "Warrion.h"

void Warrion::React()
{
	std::cout << "Вы натолкнулись на воина..." << '\n';
	preview_battle();
}

bool Warrion::is_one_time()
{
	return this->is_dead();
}