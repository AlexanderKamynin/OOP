#include "Mediator.h"


Mediator::Mediator() {
    this->command_reader = new CommandReader;
    this->controller = new Controller;
}

void Mediator::start_game() {
    std::cout << "Введите размеры игрового поля (значения от 10 до 30)" << '\n';
    std::cout << "если высота или ширина будут введены неверно, то соответсвующие размеры будут сделаны по умолчанию(10)" << '\n';
    std::cout << "Введите высоту поля:" << '\n';
    int height = command_reader->read_size();
    std::cout << "Введите ширину поля:" << '\n';
    int width = command_reader->read_size();
    controller->create_field(height, width);
    game();
}

void Mediator::game() {
    std::cout << "Управление:\nналевo - " << "a" << "\nнаправо - " << "d"
        << "\nвверх - " << "w" << "\nвниз - " << "s" << '\n';
    std::cout << "Выход из игры - " << "exit" << '\n';

    controller->update_visualization();
    while (1) {
        CommandReader::COMMANDS current_command = command_reader->read_command();
        if (current_command == CommandReader::COMMANDS::EXIT) {
            break;
        }
        if (current_command == CommandReader::COMMANDS::LEFT || current_command == CommandReader::COMMANDS::RIGHT || current_command == CommandReader::COMMANDS::UP
            || current_command == CommandReader::COMMANDS::DOWN) {
            system("cls");
            controller->move_player(current_command);
            controller->update_visualization();
        }
    }
}

Mediator::~Mediator() {
    delete command_reader;
    delete controller;
}