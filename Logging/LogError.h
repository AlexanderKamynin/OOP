#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <vector>


class LogError : public IObserver
{
public:
	LogError(std::vector<ISubject*> subjects);

	void update(Message& msg) override;

	void activate();

	~LogError();
private:	
	std::vector<ISubject*> subjects;
	bool is_activate;
};
