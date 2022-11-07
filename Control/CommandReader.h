#pragma once
#include "../EnumClass.h"
#include "Settings/Settings.h"
#include <iostream>
#include <vector>
#include <string>


class CommandReader {
public:

    CommandReader();

    EnumClass::COMMANDS read_command();

    int read_size();

    std::vector<int> read_numbers(); 

    bool read_agree();

    Settings* get_setting();

    ~CommandReader();
private:
    Settings* settings;

    bool string_is_digit(std::string str);
};