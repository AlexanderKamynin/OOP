#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <iostream>
#include <vector>


class LogGame : public IObserver
{
public:
	LogGame(std::vector<ISubject*> subjects);
	
	void update(const Message& msg) override;

	~LogGame();
private:
	std::vector<ISubject*> subjects;
};

