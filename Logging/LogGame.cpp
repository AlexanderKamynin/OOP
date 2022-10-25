#include "LogGame.h"

LogGame::LogGame(ISubject* subject)
{
	this->subject = subject;
	subject->attach(this);
}

void LogGame::update(const Message& msg)
{
	std::cout << msg;
}

LogGame::~LogGame()
{
	subject->detach(this);
}

