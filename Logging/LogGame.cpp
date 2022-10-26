#include "LogGame.h"

LogGame::LogGame(std::vector <ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
	this->is_activate = false;
}

void LogGame::update(Message& msg)
{
	if (this->is_activate && msg.get_prefix() == "log_game:") 
	{
			std::cout << msg;
	}
}

void LogGame::activate()
{
	this->is_activate = true;
}

LogGame::~LogGame()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}

