#pragma once
#include "CommandReader.h"
#include "Controller.h"


class Mediator {
public:

    Mediator();

    void start_game();

    ~Mediator();
private:
    void game();

    CommandReader* command_reader;
    Controller* controller;
};
