#pragma once
#include <string>
#include <map>

class EnumClass
{
public:
	enum LogLevels {
		LOG_GAME,
		LOG_GAME_STATUS,
		LOG_ERROR
	};
	
	std::map<LogLevels, std::string> log_levels = {
		{LogLevels::LOG_GAME, "LOG_GAME"},
		{LogLevels::LOG_GAME_STATUS, "LOG_GAME_STATUS"},
		{LogLevels::LOG_ERROR, "LOG_ERROR"}
	};
};

