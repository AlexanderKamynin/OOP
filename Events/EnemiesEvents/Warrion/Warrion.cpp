#include "Warrion.h"

void Warrion::React()
{
	set_stats();
	std::cout << "�� ������������ �� �����..." << '\n';
	preview_battle();
}

void Warrion::set_gold(int gold)
{
	this->gold = gold;
}

void Warrion::set_passkey(int passkey)
{
	this->passkey += passkey;
}

void Warrion::set_stats()
{
	this->health = 40;
	this->damage = 5;
}