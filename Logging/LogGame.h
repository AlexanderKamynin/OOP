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
	
	void add_subjects(std::vector<ISubject*> subjects) override;

	void add_log_printer(ILogPrinter* log_printer) override;

	void activate();

	~LogGame();
private:
	ILogPrinter* log_printer;
	std::vector<ISubject*> subjects;
	bool is_activate;
};

