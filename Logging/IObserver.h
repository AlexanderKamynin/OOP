#pragma once
#include "Message.h"


class IObserver {
public:
	virtual void update(Message& msg) = 0;
	virtual void activate() = 0;
	virtual ~IObserver() {};
};