#pragma once
#include "Message.h"


class IObserver {
public:
	virtual void update(const Message& msg) = 0;
	virtual ~IObserver() {};
};