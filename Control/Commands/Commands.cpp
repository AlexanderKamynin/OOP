#include "Commands.h"

Commands::Commands()
{
	this->control_reader = new ControlReader();
	std::map<EnumClass::COMMANDS, std::string> tmp_commands = this->control_reader->read_control_commands();
    if (tmp_commands.size() != this->commands.size()) {
        std::cout << "Ошибка при обработке файла control.txt. Были использованы стандартные команды" << '\n';
    }
    else {
        this->commands = tmp_commands;
        std::cout << "Файл control.txt был обработан без ошибок" << '\n';
    }
}

std::map<EnumClass::COMMANDS, std::string> Commands::get_commands()
{
	return this->commands;
}

std::map<EnumClass::COMMANDS, std::string> Commands::get_commands_info()
{
    return this->commands_info;
}

Commands::~Commands()
{
	delete this->control_reader;
}
