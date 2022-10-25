#pragma once
#include "IObserver.h"
#include "ISubject.h"


class LogError : public IObserver
{
public:
	LogError(ISubject* subject);

	void update(const Message& msg) override;

	~LogError();
private:
	ISubject* subject;
};
