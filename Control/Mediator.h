#pragma once
#include "../Control/CommandReader/ICommandReader.h"
#include "../Control/CommandReader/CommandReader.h"
#include "Controller.h"
#include "../Control/Commands/Commands.h"
#include <string>

class Mediator {
public:

    Mediator();

    void start_game();

    ~Mediator();
private:
    void game();
    void choose_log_level();
    void choose_log_printer();
    void print_commands();
    ICommandReader* command_reader;
    Controller* controller;
    Commands* commands;
};
