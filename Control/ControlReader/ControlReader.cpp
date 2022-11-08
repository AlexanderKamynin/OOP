#include "ControlReader.h"


ControlReader::ControlReader(const std::string& filename)
{
    this->control_file.open(filename, std::ios_base::in);
}

std::map<EnumClass::COMMANDS, std::string> ControlReader::read_control_commands()
{
    std::map<EnumClass::COMMANDS, std::string> commands;
    std::string inputs_line;
    if (this->control_file.is_open()) {
        while (std::getline(this->control_file, inputs_line)) {
            if (check_control(inputs_line)) {
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
                instruction_info.push_back(str);
                EnumClass::COMMANDS command = this->instruction_prefix.find(instruction_info[0])->second;
                commands.insert(std::make_pair(command, instruction_info[1]));
            }
        }
    }
    return commands;
}

bool ControlReader::check_control(std::string instruction)
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
        if (check_control_prefix(instruction_info[0]) && check_control_command(instruction_info[1])) {
            return true;
        }
        return false;
    }
}

bool ControlReader::check_control_prefix(std::string instruction_prefix)
{
    auto It = this->instruction_prefix.find(instruction_prefix);
    if (It != this->instruction_prefix.end()) {
        return true;
    }
    return false;
}

bool ControlReader::check_control_command(std::string inctruction_command)
{
    if (inctruction_command.length() != 0) {
        return true;
    }
    return false;
}

ControlReader::~ControlReader()
{
    this->control_file.close();
}
