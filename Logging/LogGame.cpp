#include "LogGame.h"

LogGame::LogGame(std::vector <ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void LogGame::update(const Message& msg)
{
	std::cout << msg;
}

LogGame::~LogGame()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}

