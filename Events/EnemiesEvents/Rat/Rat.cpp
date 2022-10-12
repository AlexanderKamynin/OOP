#include "Rat.h"

void Rat::React() {
	set_stats();
	std::cout << "Перед вами крыса..." << '\n';
	preview_battle();
}

void Rat::set_gold(int gold) {
	this->gold = gold;
}

void Rat::set_passkey(int passkey) {
	this->passkey += passkey;
}

void Rat::set_stats() {
	this->health = 20;
	this->damage = 3;
}