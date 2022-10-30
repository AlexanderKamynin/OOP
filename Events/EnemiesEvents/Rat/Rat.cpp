#include "Rat.h"

void Rat::React() 
{
	Message msg(EnumClass::LOG_GAME, "Rat::React()");
	this->notify(msg);
	std::cout << "Перед вами крыса..." << '\n';
	preview_battle();
}

bool Rat::is_one_time()
{
	return this->is_dead();
}