#include "Boss.h"

void Boss::React()
{
	set_stats();
	std::cout << "ѕеред вами крупное существо, похоже это босс..." << '\n';
	preview_battle();
	if (is_dead()) {
		std::cout << "Ќайдите местоположение выхода..." << '\n';
	}
}

void Boss::set_gold(int gold)
{
	this->gold = gold;
}

void Boss::set_passkey(int passkey)
{
	this->passkey += passkey;
}

void Boss::set_stats()
{
	this->health = 60;
	this->damage = 15;
}
