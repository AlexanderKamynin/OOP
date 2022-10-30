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
	if (msg.get_log_level() == EnumClass::LOG_ERROR)
	{
		this->log_printer->print_log(msg);
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

void LogError::add_log_printer(ILogPrinter* log_printer) {
	this->log_printer = log_printer;
}

LogError::~LogError()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}
