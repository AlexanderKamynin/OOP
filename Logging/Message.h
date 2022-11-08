#pragma once
#include "../EnumClass.h"
#include <iostream>
#include <map>
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

	std::map<EnumClass::LogLevels, std::string> log_levels = {
		{EnumClass::LogLevels::LOG_GAME, "LOG_GAME"},
		{EnumClass::LogLevels::LOG_GAME_STATUS, "LOG_GAME_STATUS"},
		{EnumClass::LogLevels::LOG_ERROR, "LOG_ERROR"}
	};
};

