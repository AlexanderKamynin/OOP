#pragma once
#include "Message.h"
#include <vector>

//forward declaration
class ISubject;

class IObserver {
public:
	virtual void update(Message& msg) = 0;
	virtual void activate() = 0;
	virtual void add_subjects(std::vector<ISubject*> subjects) = 0;
	virtual ~IObserver() {};
};