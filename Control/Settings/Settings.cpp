#include "Settings.h"


Settings::Settings(const std::string& filename)
{
    this->settings_file.open(filename, std::ios_base::in);
}

void Settings::read_settings()
{
    std::map<EnumClass::COMMANDS, std::string> commands;
    std::string inputs_line;
    if (this->settings_file.is_open()) {
        while (std::getline(this->settings_file, inputs_line)) {
            if (check_instruction(inputs_line)) {
                std::vector<std::string> instruction_info;
                std::string str;
                for (auto x : inputs_line)
                {
                    if (x == ':')
                    {
                        instruction_info.push_back(str);
                        str = "";
                    }
                    else
                    {
                        str += x;
                    }
                }
                EnumClass enum_class;
                instruction_info.push_back(str);
                EnumClass::COMMANDS command = enum_class.instruction_prefix.find(instruction_info[0])->second;
                commands.insert(std::make_pair(command, instruction_info[1]));
            }
        }
    }
    if (commands.size() != this->commands.size()) {
        std::cout << "Файл settings.txt содержит ошибки. Были использованы стандартные команды управления" << '\n';
    }
    else {
        this->commands = commands;
        std::cout << "Файл settings.txt не содержит ошибок. Были использованы команды управления, заданные пользователем" << '\n';
    }
}

bool Settings::check_instruction(std::string instruction)
{
    bool instruction_is_valid = false;
    std::vector<std::string> instruction_info;
    std::string str;
    for (auto x : instruction)
    {
        if (x == ':')
        {
            instruction_info.push_back(str);
            str = "";
        }
        else
        {
            str += x;
        }
    }
    instruction_info.push_back(str);
    if (instruction_info.size() != 2) {
        return false;
    }
    else {
        if (check_instruction_prefix(instruction_info[0]) && check_instruction_command(instruction_info[1])) {
            return true;
        }
        return false;
    }
}

bool Settings::check_instruction_prefix(std::string instruction_prefix)
{
    EnumClass enum_class;
    auto It = enum_class.instruction_prefix.find(instruction_prefix);
    if (It != enum_class.instruction_prefix.end()) {
        return true;
    }
    return false;
}

bool Settings::check_instruction_command(std::string inctruction_command)
{
    if (inctruction_command.length() != 0) {
        return true;
    }
    return false;
}

std::map<EnumClass::COMMANDS, std::string> Settings::get_commands()
{
    return this->commands;
}

Settings::~Settings()
{
    this->settings_file.close();
}
