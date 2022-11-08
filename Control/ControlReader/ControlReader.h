#pragma once
#include "../../EnumClass.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

class ControlReader
{
public:
	ControlReader(const std::string& filename = "control.txt");

	std::map<EnumClass::COMMANDS, std::string> read_control_commands();

	~ControlReader();
private:
	std::ifstream control_file;

	std::map<std::string, EnumClass::COMMANDS> instruction_prefix = {
		{"LEFT", EnumClass::COMMANDS::LEFT},
		{"RIGHT", EnumClass::COMMANDS::RIGHT},
		{"UP", EnumClass::COMMANDS::UP},
		{"DOWN", EnumClass::COMMANDS::DOWN},
		{"EXIT", EnumClass::COMMANDS::EXIT}
	};

	bool check_control(std::string instruction);

	bool check_control_prefix(std::string instruction_prefix);

	bool check_control_command(std::string inctruction_command);
};

