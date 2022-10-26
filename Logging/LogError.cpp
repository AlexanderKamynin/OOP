#include "LogError.h"

LogError::LogError(std::vector <ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
	this->is_activate = false;
}

void LogError::update(Message& msg)
{
	if (this->is_activate && msg.get_prefix() == "log_error:")
	{
		std::cout << msg;
	}
}

void LogError::add_subjects(std::vector<ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void LogError::activate()
{
	this->is_activate = true;
}

LogError::~LogError()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}
