#pragma once
#include "IObserver.h"


class ISubject
{
public:
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify(const Message &msg) = 0;
	virtual ~ISubject() {};
};

