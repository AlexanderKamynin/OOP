#include "Rat.h"

void Rat::React() {
	std::cout << "����� ���� �����..." << '\n';
	preview_battle();
}

bool Rat::is_one_time()
{
	return this->is_dead();
}