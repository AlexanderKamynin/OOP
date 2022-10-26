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
	if (this->is_activate && msg.get_prefix() == "log_game_status:")
	{
		std::cout << msg;
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

LogGameStatus::~LogGameStatus()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}
