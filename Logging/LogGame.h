#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <iostream>
#include <vector>


class LogGame : public IObserver
{
public:
	LogGame(std::vector<ISubject*> subjects);
	
	void update(Message& msg) override;

	void activate();

	~LogGame();
private:
	std::vector<ISubject*> subjects;
	bool is_activate;
};

