#include "Boss.h"

void Boss::React()
{
	set_stats();
	std::cout << "����� ���� ������� ��������, ������ ��� ����..." << '\n';
	preview_battle();
	if (is_dead()) {
		std::cout << "������� �������������� ������..." << '\n';
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
