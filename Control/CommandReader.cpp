#include "CommandReader.h"


EnumClass::COMMANDS CommandReader::read_command() {
    EnumClass enum_class;
    std::string command;
    std::cin >> command;
    auto It = enum_class.commands.find(command);
    if (It != enum_class.commands.end()) {
        return It->second;
    }
    return EnumClass::ERROR;
}

int CommandReader::read_size() {
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
}

bool CommandReader::string_is_digit(std::string str) {
    for (char c : str)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}