#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <vector>

class LogGameStatus : public IObserver
{
public:
	LogGameStatus(std::vector <ISubject*> subjects);

	void update(Message& msg) override;

	void activate();

	~LogGameStatus();
private:
	std::vector <ISubject*> subjects;
	bool is_activate;
};

