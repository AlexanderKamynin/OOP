#include "Rat.h"

void Rat::React() {
	set_stats();
	std::cout << "����� ���� �����..." << '\n';
	preview_battle();
}

void Rat::set_gold(int gold) {
	this->gold = gold;
}

void Rat::set_passkey() {
	this->passkey += 1;
}

void Rat::set_stats() {
	this->health = 20;
	this->damage = 3;
}