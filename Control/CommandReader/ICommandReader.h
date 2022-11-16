#pragma once
#include "../../EnumClass.h"
#include <vector>


class ICommandReader
{
public:
    virtual EnumClass::COMMANDS read_command() = 0;

    virtual int read_number() = 0;

    virtual std::vector<int> read_numbers() = 0;

    virtual bool read_agree() = 0;

    virtual bool string_is_digit(std::string str) = 0;

    virtual ~ICommandReader() = 0 {};
};

