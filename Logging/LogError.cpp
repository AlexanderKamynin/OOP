#include "LogError.h"

LogError::LogError(std::vector <ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void LogError::update(const Message& msg)
{
	std::cout << msg;
}

LogError::~LogError()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}
