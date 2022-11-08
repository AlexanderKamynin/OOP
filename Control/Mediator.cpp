#include "Mediator.h"


Mediator::Mediator() {
    this->commands = new Commands();
    this->command_reader = new CommandReader(this->commands);
    this->controller = new Controller;
}

void Mediator::start_game() {
    choose_log_level();
    Message msg(EnumClass::LogLevels::LOG_GAME_STATUS, "Game is start");
    this->controller->get_logger()->update(msg);
    std::cout << "Введите размеры игрового поля [10-30]" << '\n';
    std::cout << "\tВведите высоту поля:" << '\n';
    int height = command_reader->read_number();
    std::cout << "\tВведите ширину поля:" << '\n';
    int width = command_reader->read_number();
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
            height = command_reader->read_number();
            std::cout << "Введите ширину поля:" << '\n';
            width = command_reader->read_number();
        }
    }
    controller->create_field(height, width);
    game();
}

void Mediator::game() {
    print_commands();
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
        std::cout << "Выберите уровни логирования через запятую:" << std::endl;
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
                        bool is_contain = false;
                        for (int i = 0; i < log_levels.size(); i++) {
                            if (log_levels[i] == num) {
                                is_contain = true;
                                break;
                            }
                        }
                        if (is_contain == false) {
                            log_levels.push_back((EnumClass::LogLevels)num);
                        }
                    }
                }
                if (log_levels.size() == 0) {
                    std::cout << "Введите корректно уровни логирования (ex:[1,2,3])" << std::endl;
                }
                else {
                    choose_log_printer();
                    controller->create_logger(log_levels);
                    break;
                }
            }
            else {
                std::cout << "Введите корректно уровни логирования (ex:[1,2,3])" << std::endl;
            }
        }
    }
    else {
        controller->create_logger(std::vector<EnumClass::LogLevels>());
    }
}

void Mediator::choose_log_printer() {
    std::vector<int> numbers;
    std::cout << "Выберите формат вывода отслеживаемых уровней через запятую:" << std::endl;
    std::cout
        << "1 - терминал" << std::endl
        << "2 - файл" << std::endl;
    while (true) {
        numbers = command_reader->read_numbers();
        if (numbers.size() != 0) {
            std::vector<int> log_printers;
            for (auto num : numbers) {
                if (num >= 1 && num <= 2) {
                    bool is_contain = false;
                    for (int i = 0; i < log_printers.size(); i++) {
                        if (log_printers[i] == num) {
                            is_contain = true;
                            break;
                        }
                    }
                    if (is_contain == false) {
                        log_printers.push_back(num);
                    }
                }
            }
            if (log_printers.size() == 0) {
                std::cout << "Введите корректно формат вывода (ex:[1,2])" << std::endl;
            }
            else {
                controller->create_log_printers(log_printers);
                break;
            }
        }
        else {
            std::cout << "Введите корректно формат вывода (ex:[1,2])" << std::endl;
        }
    }
}

void Mediator::print_commands()
{
    std::cout << "Команды управления:" << '\n';
    for (auto elem : this->commands->get_commands()) {
        std::cout << elem.second << " - " << this->commands->get_commands_info()[elem.first] << '\n';
    }
}

Mediator::~Mediator() {
    delete command_reader;
    delete controller;
}