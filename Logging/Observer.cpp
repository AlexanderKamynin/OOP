#include "Observer.h"

Observer::Observer(std::vector <ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void Observer::update(Message& msg)
{
	for (auto level : this->levels_to_log) {
		if (level == msg.get_log_level()){
			for (auto printer : this->log_printers) {
				printer->print_log(msg);
			}
		}
	}
}

void Observer::add_subjects(std::vector<ISubject*> subjects)
{
	this->subjects = subjects;
	for (auto elem : subjects) {
		elem->attach(this);
	}
}

void Observer::add_log_printers(std::vector<ILogPrinter*> log_printers)
{
	for (auto elem : log_printers) {
		this->log_printers.push_back(elem);
	}
}

void Observer::add_levels_to_log(std::vector<EnumClass::LogLevels> levels_to_log)
{
	for (auto elem : levels_to_log) {
		bool is_contain = false;
		for (int i = 0; i < this->levels_to_log.size(); i++) {
			if (this->levels_to_log[i] == elem) {
				is_contain = true;
				break;
			}
		}
		if (is_contain == false) {
			this->levels_to_log.push_back(elem);
		}
	}
}

Observer::~Observer()
{
	for (auto elem : subjects) {
		elem->detach(this);
	}
}