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
	if (msg.get_log_level() == EnumClass::LOG_GAME)
	{
		this->log_printer->print_log(msg);
	}
}

void LogGame::add_subjects(std::vector<ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void LogGame::activate()
{
	this->is_activate = true;
}

void LogGame::add_log_printer(ILogPrinter* log_printer) {
	this->log_printer = log_printer;
}

LogGame::~LogGame()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}

