#include "LogGameStatus.h"

LogGameStatus::LogGameStatus(std::vector <ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
	this->is_activate = false;
}

void LogGameStatus::update(Message& msg)
{
	if (this->is_activate && msg.get_log_level() == EnumClass::LOG_GAME_STATUS)
	{
		this->log_printer->print_log(msg);
	}
}

void LogGameStatus::add_subjects(std::vector<ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void LogGameStatus::activate()
{
	this->is_activate = true;
}

void LogGameStatus::add_log_printer(ILogPrinter* log_printer) {
	this->log_printer = log_printer;
}

LogGameStatus::~LogGameStatus()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}
