#pragma once
#include "../EnumClass.h"
#include <iostream>
#include <string>

class Message
{
public:
	Message(EnumClass::LogLevels log_level, std::string msg);

	EnumClass::LogLevels get_log_level();

	friend std::ostream& operator << (std::ostream& out, const Message& obj);
private:
	std::string msg;
	EnumClass::LogLevels prefix;
};

