#include "Commands.h"

Commands::Commands()
{
	this->control_reader = new ControlReader();
	std::map<EnumClass::COMMANDS, std::string> tmp_commands = this->control_reader->read_control_commands();
    if (tmp_commands.size() != this->commands.size()) {
        std::cout << "Ошибка при обработке файла control.txt. Были использованы стандартные команды" << '\n';
        this->commands_file_is_correct = false;
    }
    else {
        this->commands = tmp_commands;
        this->commands_file_is_correct = true;
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

bool Commands::commands_file_correct()
{
    return this->commands_file_is_correct;
}

Commands::~Commands()
{
	delete this->control_reader;
}
