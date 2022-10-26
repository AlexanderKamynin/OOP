#pragma once
#include "../Logging/Message.h"


class ILogPrinter
{
public:
	virtual void print_log(const Message& msg) = 0;
	virtual ~ILogPrinter() = 0 {};
};

