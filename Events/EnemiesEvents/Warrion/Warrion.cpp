#include "Warrion.h"

void Warrion::React()
{
	Message msg(EnumClass::LOG_GAME, "Warrion::React()");
	this->notify(msg);
	std::cout << "�� ������������ �� �����..." << '\n';
	preview_battle();
}

bool Warrion::is_one_time()
{
	return this->is_dead();
}