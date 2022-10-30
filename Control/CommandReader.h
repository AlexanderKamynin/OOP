#pragma once
#include "../EnumClass.h"
#include <iostream>
#include <string>


class CommandReader {
public:

    CommandReader() = default;

    EnumClass::COMMANDS read_command();

    int read_size();

    bool read_agree(); 

    ~CommandReader() = default;
private:
    bool string_is_digit(std::string str);
};