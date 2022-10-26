#pragma once
#include "CommandReader.h"
#include "Controller.h"
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
    CommandReader* command_reader;
    Controller* controller;
};
