#include "CommandReader.h"

CommandReader::CommandReader(Commands* commands) {
    this->commands = commands;
}

EnumClass::COMMANDS CommandReader::read_command() {
    std::string command;
    std::cin >> command;
    for (auto elem : this->commands->get_commands()) {
        if (elem.second == command) {
            return elem.first;
        }
    }
    return EnumClass::ERROR;
}

int CommandReader::read_number() {
    std::string size;
    std::cin >> size;
    if (string_is_digit(size)) {
        return std::stoi(size);
    }
    return -1;
}

bool CommandReader::read_agree()
{
    std::string agree = "";
    while (agree != "yes" && agree != "no") {
        std::cin >> agree;
        if (agree == "yes") {
            return true;
        }
        if (agree == "no") {
            return false;
        }
        std::cout << "¬ведите [yes/no]" << '\n';
    }
    return false;
}

std::vector<int> CommandReader::read_numbers()
{
    std::vector<int> numbers;
    std::string str;
    std::string line;
    std::cin >> line;
    for (auto x : line)
    {
        if (x == ',')
        {
            if (string_is_digit(str)) {
                numbers.push_back(std::stoi(str));
            }
            else {
                numbers.push_back(-1);
            }
            str = "";
        }
        else
        {
            str += x;
        }
    }
    if (string_is_digit(str)) {
        numbers.push_back(std::stoi(str));
    }
    return numbers;
}

bool CommandReader::string_is_digit(std::string str) {
    if (str.size() == 0) {
        return false;
    }
    for (char c : str)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}