#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <iostream>

class LogGame : public IObserver
{
public:
	LogGame(ISubject* subject);
	
	void update(const Message& msg) override;

	~LogGame();
private:
	ISubject* subject;
};

