#include "Rat.h"

void Rat::React() 
{
	Message msg("log_game", "react from rat\n");
	this->notify(msg);
	std::cout << "Перед вами крыса..." << '\n';
	preview_battle();
}

bool Rat::is_one_time()
{
	return this->is_dead();
}