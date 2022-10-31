#pragma once
#include "Message.h"
#include "ILogPrinter.h"
#include "../EnumClass.h" 
#include <vector>

//forward declaration
class ISubject;

class IObserver {
public:
	virtual void update(Message& msg) = 0;
	virtual ~IObserver() {};
};