#include "Mediator.h"


Mediator::Mediator() {
    this->command_reader = new CommandReader;
    this->controller = new Controller;
}

void Mediator::start_game() {
    std::cout << "Введите размеры игрового поля [10-30]" << '\n';
    std::cout << "\tВведите высоту поля:" << '\n';
    int height = command_reader->read_size();
    std::cout << "\tВведите ширину поля:" << '\n';
    int width = command_reader->read_size();
    while (height < 10 || height > 30 || width < 10 || width > 30) {
        std::cout << "Один из параметров введен неверно" << '\n';
        std::cout << "Хотите использовать значение по умолчанию (10x10)? [yes/no]" << '\n';
        if (command_reader->read_agree()) {
            break;
        }
        else {
            std::cout << "Введите высоту поля:" << '\n';
            height = command_reader->read_size();
            std::cout << "Введите ширину поля:" << '\n';
            width = command_reader->read_size();
        }
    }
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
        controller->get_defeat_event()->React();
        if (controller->get_defeat_event()->is_activate()) {
            break;
        }
        if (controller->get_exit_event()->is_activate()) {
            break;
        }
    }
}

Mediator::~Mediator() {
    delete command_reader;
    delete controller;
}