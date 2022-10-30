﻿#include "Mediator.h"


Mediator::Mediator() {
    this->command_reader = new CommandReader;
    this->controller = new Controller;
}

void Mediator::start_game() {
    choose_log_level();
    Message msg(EnumClass::LogLevels::LOG_GAME_STATUS, "Game is start");
    this->controller->get_logger()->update(msg);
    std::cout << "Введите размеры игрового поля [10-30]" << '\n';
    std::cout << "\tВведите высоту поля:" << '\n';
    int height = command_reader->read_size();
    std::cout << "\tВведите ширину поля:" << '\n';
    int width = command_reader->read_size();
    while (height < 10 || height > 30 || width < 10 || width > 30) {
        Message msg(EnumClass::LogLevels::LOG_ERROR, "Mediator::start_game(),incorrect values for initializing field");
        this->controller->get_logger()->update(msg);
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
        EnumClass::COMMANDS current_command = command_reader->read_command();
        if (current_command == EnumClass::COMMANDS::EXIT) {
            Message msg(EnumClass::LOG_GAME_STATUS, "Game is end, player input the exit command");
            this->controller->get_logger()->update(msg);
            break;
        }

        if (current_command != EnumClass::COMMANDS::ERROR) {
            system("cls");
            controller->move_player(current_command);
            controller->update_visualization();
        }
        else {
            Message msg(EnumClass::LogLevels::LOG_ERROR, "Mediator::game(), incorrect input value");
            this->controller->get_logger()->update(msg);
        }
        controller->get_defeat_event()->React();
        if (controller->get_defeat_event()->is_activate()) {
            Message msg(EnumClass::LogLevels::LOG_GAME_STATUS, "Game is end, player die");
            this->controller->get_logger()->update(msg);
            break;
        }
        if (controller->get_exit_event()->is_activate()) {
            Message msg(EnumClass::LogLevels::LOG_GAME_STATUS, "Game is end, player win");
            this->controller->get_logger()->update(msg);
            break;
        }
    }
}

void Mediator::choose_log_level()
{
    std::vector<int> numbers;
    std::cout << "Хотите ли вы логировать игру?[yes/no]" << std::endl;
    if (command_reader->read_agree()) {
        std::cout << "Выберите уровни логирования через пробел" << std::endl;
        std::cout
            << "1 - логирование поля, игрока, событий" << std::endl
            << "2 - логирование состояния игры" << std::endl
            << "3 - логирование критических состояний и ошибок" << std::endl;
        while (true) {
            numbers = command_reader->read_numbers();
            if (numbers.size() != 0) {
                std::vector<EnumClass::LogLevels> log_levels;
                for (auto num : numbers) {
                    if (num >= 1 && num <= 3) {
                        log_levels.push_back((EnumClass::LogLevels)num);
                    }
                }
                if (log_levels.size() != numbers.size()) {
                    std::cout << "Введите корректно уровни логирования (ex:[1 2 3])" << std::endl;
                }
                else {
                    choose_log_printer();
                    controller->create_logger(log_levels);
                    break;
                }
            }
            else {
                std::cout << "Пустой ввод. Введите корректно уровни логирования (ex:[1 2 3])" << std::endl;
            }
        }
    }
    else {
        controller->create_logger(std::vector<EnumClass::LogLevels>());
    }
}

void Mediator::choose_log_printer() {
    std::string printer = "";
    std::cout << "Выберите формат вывода отслеживаемых сведений" << std::endl;
    std::cout 
        << "[terminal] - вывод в терминал" << std::endl
        << "[file] - вывод в файл" << std::endl
        << "[termfile] - вывод в терминал и файл" << std::endl;
    while (true) {
        std::cin >> printer;
        if (printer == "terminal" || printer == "file" || printer == "termfile") {
            break;
        }
        else {
            std::cout << "Введите [terminal][file][termfile]\n";
        }
    }
    controller->create_log_printer(printer);
}

Mediator::~Mediator() {
    delete command_reader;
    delete controller;
}