#pragma once
#include <iostream>
#include <map>
#include <string>


class CommandReader {
public:
    enum COMMANDS {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        EXIT,
        ERROR
    };

    CommandReader() = default;

    COMMANDS read_command();

    int read_size();

    bool read_agree(); 

    ~CommandReader() = default;
private:
    bool string_is_digit(std::string str);

    std::map<std::string, COMMANDS> commands = {
            {"a", COMMANDS::LEFT},
            {"d", COMMANDS::RIGHT},
            {"w", COMMANDS::UP},
            {"s", COMMANDS::DOWN},
            {"exit", COMMANDS::EXIT}
    };
};