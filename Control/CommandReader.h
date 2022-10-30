#pragma once
#include "../EnumClass.h"
#include <iostream>
#include <vector>
#include <string>


class CommandReader {
public:

    CommandReader() = default;

    EnumClass::COMMANDS read_command();

    int read_size();

    std::vector<int> read_numbers(); 

    bool read_agree();

    ~CommandReader() = default;
private:
    bool string_is_digit(std::string str);
};