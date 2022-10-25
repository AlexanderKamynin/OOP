#include "LogError.h"

LogError::LogError(ISubject* subject)
{
	this->subject = subject;
	subject->attach(this);
}

void LogError::update(const Message& msg)
{

}

LogError::~LogError()
{
	this->subject->detach(this);
}
