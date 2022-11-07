#pragma once
#include "../../EnumClass.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

class Settings
{
public:
	Settings(const std::string& filename = "settings.txt");

	void read_settings();

	std::map < EnumClass::COMMANDS, std::string> get_commands();

	~Settings();
private:
	std::ifstream settings_file;

	std::map<EnumClass::COMMANDS, std::string> commands = {
		{EnumClass::COMMANDS::LEFT, "a"},
		{EnumClass::COMMANDS::RIGHT, "d"},
		{EnumClass::COMMANDS::UP, "w"},
		{EnumClass::COMMANDS::DOWN, "s"},
		{EnumClass::COMMANDS::EXIT, "exit"}
	};

	bool check_instruction(std::string instruction);

	bool check_instruction_prefix(std::string instruction_prefix);

	bool check_instruction_command(std::string inctruction_command);
};

