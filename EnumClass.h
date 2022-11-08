#pragma once
#include <string>
#include <map>

class EnumClass
{
public:
	enum LogLevels {
		LOG_GAME = 1,
		LOG_GAME_STATUS = 2,
		LOG_ERROR = 3
	};

	enum COMMANDS {
		LEFT,
		RIGHT,
		UP,
		DOWN,
		EXIT,
		ERROR
	};
};

