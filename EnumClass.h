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

	std::map<LogLevels, std::string> log_levels = {
		{LogLevels::LOG_GAME, "LOG_GAME"},
		{LogLevels::LOG_GAME_STATUS, "LOG_GAME_STATUS"},
		{LogLevels::LOG_ERROR, "LOG_ERROR"}
	};

	enum COMMANDS {
		LEFT,
		RIGHT,
		UP,
		DOWN,
		EXIT,
		ERROR
	};

	std::map<std::string, COMMANDS> instruction_prefix = {
		{"LEFT", COMMANDS::LEFT},
		{"RIGHT", COMMANDS::RIGHT},
		{"UP", COMMANDS::UP},
		{"DOWN", COMMANDS::DOWN},
		{"EXIT", COMMANDS::EXIT}
	};

	std::map<COMMANDS, std::string> commands_info = {
		{COMMANDS::LEFT, "Влево"},
		{COMMANDS::RIGHT, "Вправо"},
		{COMMANDS::UP, "Вверх"},
		{COMMANDS::DOWN, "Вниз"},
		{COMMANDS::EXIT, "Выход из игры"}
	};
};

