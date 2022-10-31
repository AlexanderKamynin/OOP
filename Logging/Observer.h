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

	void add_subjects(std::vector<ISubject*> subjects);

	void add_log_printers(std::vector<ILogPrinter*> log_printers);

	void add_levels_to_log(std::vector<EnumClass::LogLevels> levels_to_log);

	~Observer();
private:
	std::vector<ILogPrinter*> log_printers;
	std::vector<ISubject*> subjects;
	std::vector<EnumClass::LogLevels> levels_to_log;
};



