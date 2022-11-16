#pragma once
#include "../../EnumClass.h"
#include "../ControlReader/ControlReader.h"
#include <map>
#include <string>

class Commands
{
public:
	Commands();

	std::map<EnumClass::COMMANDS, std::string> get_commands();

	std::map<EnumClass::COMMANDS, std::string> get_commands_info();
	
	bool commands_file_correct();

	~Commands();
private:
	bool commands_file_is_correct;

	ControlReader* control_reader;

	std::map<EnumClass::COMMANDS, std::string> commands = {
		{EnumClass::COMMANDS::LEFT, "a"},
		{EnumClass::COMMANDS::RIGHT, "d"},
		{EnumClass::COMMANDS::UP, "w"},
		{EnumClass::COMMANDS::DOWN, "s"},
		{EnumClass::COMMANDS::EXIT, "exit"}
	};

	std::map<EnumClass::COMMANDS, std::string> commands_info = {
		{EnumClass::COMMANDS::LEFT, "Влево"},
		{EnumClass::COMMANDS::RIGHT, "Вправо"},
		{EnumClass::COMMANDS::UP, "Вверх"},
		{EnumClass::COMMANDS::DOWN, "Вниз"},
		{EnumClass::COMMANDS::EXIT, "Выход из игры"}
	};
};

