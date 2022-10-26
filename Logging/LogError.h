#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <vector>


class LogError : public IObserver
{
public:
	LogError(std::vector<ISubject*> subjects);

	void update(const Message& msg) override;

	~LogError();
private:	
	std::vector<ISubject*> subjects;
};
