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

bool CommandReader::string_is_digit(std::string str) {
    for (char c : str)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}