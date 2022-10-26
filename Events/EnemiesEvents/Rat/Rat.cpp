#include "Rat.h"

void Rat::React() 
{
	this->notify(Message("log_game", "react from rat\n"));
	std::cout << "Перед вами крыса..." << '\n';
	preview_battle();
}

bool Rat::is_one_time()
{
	return this->is_dead();
}