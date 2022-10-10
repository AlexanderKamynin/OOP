#include "CommandReader.h"


CommandReader::COMMANDS CommandReader::read_command() {
    std::string command;
    std::cin >> command;
    auto It = commands.find(command);
    if (It != commands.end()) {
        return It->second;
    }
    return COMMANDS::ERROR;
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
    while (1) {
        std::cin >> agree;
        if (agree == "yes") {
            return true;
        }
        if (agree == "no") {
            return false;
        }
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