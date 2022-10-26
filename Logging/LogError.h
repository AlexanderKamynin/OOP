#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <vector>


class LogError : public IObserver
{
public:
	LogError(std::vector<ISubject*> subjects);

	void update(Message& msg) override;
	
	void add_subjects(std::vector<ISubject*> subjects) override;

	void add_log_printer(ILogPrinter* log_printer) override;

	void activate();

	~LogError();
private:	
	ILogPrinter* log_printer;
	std::vector<ISubject*> subjects;
	bool is_activate;
};
