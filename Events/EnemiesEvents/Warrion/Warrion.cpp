#include "Warrion.h"

void Warrion::React()
{
	set_stats();
	std::cout << "Вы натолкнулись на воина..." << '\n';
	preview_battle();
}

void Warrion::set_gold(int gold)
{
	this->gold = gold;
}

void Warrion::set_passkey()
{
	this->passkey += 1;
}

void Warrion::set_stats()
{
	this->health = 40;
	this->damage = 5;
}
