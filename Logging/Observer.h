#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include <iostream>
#include <vector>


class Observer : public IObserver
{
public:
	Observer(std::vector<ISubject*> subjects);

	void update(Message& msg) override;

	void add_subjects(std::vector<ISubject*> subjects) override;

	void add_log_printer(ILogPrinter* log_printer) override;

	void add_levels_to_log(std::vector<EnumClass::LogLevels> levels_to_log);

	void activate();

	~Observer();
private:
	ILogPrinter* log_printer;
	std::vector<ISubject*> subjects;
	std::vector<EnumClass::LogLevels> levels_to_log;
	bool is_activate;
};



