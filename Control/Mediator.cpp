#include "Mediator.h"


Mediator::Mediator() {
    this->command_reader = new CommandReader;
    this->controller = new Controller;
}

void Mediator::start_game() {
    choose_log_level();
    Message msg("log_game_status", "Game is start\n");
    this->controller->get_cur_log()->update(msg);
    std::cout << "Введите размеры игрового поля [10-30]" << '\n';
    std::cout << "\tВведите высоту поля:" << '\n';
    int height = command_reader->read_size();
    std::cout << "\tВведите ширину поля:" << '\n';
    int width = command_reader->read_size();
    while (height < 10 || height > 30 || width < 10 || width > 30) {
        Message msg("log_error", "incorrect values for initializing field\n");
        this->controller->get_cur_log()->update(msg);
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
            Message msg("log_game_status", "Game is end (player input the exit command)\n");
            this->controller->get_cur_log()->update(msg);
            break;
        }
        if (current_command == CommandReader::COMMANDS::LEFT || current_command == CommandReader::COMMANDS::RIGHT || current_command == CommandReader::COMMANDS::UP
            || current_command == CommandReader::COMMANDS::DOWN) {
            system("cls");
            controller->move_player(current_command);
            controller->update_visualization();
        }
        else {
            Message msg("log_error", "incorrect input in Mediator::game()\n");
            this->controller->get_cur_log()->update(msg);
        }
        controller->get_defeat_event()->React();
        if (controller->get_defeat_event()->is_activate()) {
            Message msg("log_game_status", "Game is end (player die)\n");
            this->controller->get_cur_log()->update(msg);
            break;
        }
        if (controller->get_exit_event()->is_activate()) {
            Message msg("log_game_status", "Game is end (player win)\n");
            this->controller->get_cur_log()->update(msg);
            break;
        }
    }
}

void Mediator::choose_log_level()
{
    int log_level = 0;
    std::cout << "Выберите уровень логирования:\n";
    std::cout 
        << "0 - без логирования\n" 
        << "1 - логирование поля, игрока, событий\n" 
        << "2 - логирование состояния игры\n"
        << "3 - логирование критических состояний и ошибок\n";
    log_level = command_reader->read_size();
    while (log_level < 0 || log_level > 3) {
        std::cout << "Уровень логирования введен неверно" << '\n';
        std::cout << "Хотите использовать значение по умолчанию (0)? [yes/no]" << '\n';
        if (command_reader->read_agree()) {
            log_level = 0;
            break;
        }
        else {
            std::cout << "Выберите уровень логирования:\n";
            log_level = command_reader->read_size();
        }
    }
    if (log_level != 0) {
        choose_log_printer();
    }
    controller->create_logs(log_level);
}

void Mediator::choose_log_printer() {
    std::string printer = "";
    std::cout << "Выберите формат вывода отслеживаемых сведений\n";
    std::cout 
        << "[terminal] - вывод в терминал\n"
        << "[file] - вывод в файл\n"
        << "[termfile] - вывод в терминал и файл\n";
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