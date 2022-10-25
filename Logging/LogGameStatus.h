#pragma once
#include "IObserver.h"
#include "ISubject.h"


class LogGameStatus : public IObserver
{
public:
	LogGameStatus(ISubject* subject);

	void update(const Message& msg) override;

	~LogGameStatus();
private:
	ISubject* subject;
};

