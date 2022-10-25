#include "LogGameStatus.h"

LogGameStatus::LogGameStatus(ISubject* subject)
{
	this->subject = subject;
	subject->attach(this);
}

void LogGameStatus::update(const Message& msg)
{

}

LogGameStatus::~LogGameStatus()
{
	this->subject->detach(this);
}
