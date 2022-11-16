#pragma once
#include "../../EnumClass.h"
#include "../../Control/Commands/Commands.h"
#include "ICommandReader.h"
#include <iostream>
#include <vector>
#include <string>


class CommandReader : public ICommandReader {
public:
    CommandReader(Commands* commands);

    EnumClass::COMMANDS read_command() override;

    int read_number() override;

    std::vector<int> read_numbers() override; 

    bool read_agree() override;

    ~CommandReader() = default;
private:    
    Commands* commands;
    bool string_is_digit(std::string str) override;
};