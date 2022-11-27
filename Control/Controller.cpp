#include "Controller.h"


Controller::Controller() {
    this->field_view = nullptr;
    this->field = nullptr;
    this->player = nullptr;
    this->level_context = nullptr;
    this->log_printers = std::vector<ILogPrinter*>();
    this->logger = nullptr;
    this->defeat_event = nullptr;
    this->exit_event = nullptr;
}

void Controller::create_level(int level)
{
    this->level_context = new LevelContext(level);
    this->field = field;
    this->player = field->get_player();
    this->field_view = new FieldView(this->field);
    GameProcessEventFactory* factory = new GameProcessEventFactory(this->player);
    this->defeat_event = dynamic_cast<DefeatEvent*>(factory->createDefeatEvent());
    for (int y = 0; y < this->field->get_height(); y++) {
        for (int x = 0; x < this->field->get_width(); x++) {
            if (dynamic_cast<ExitEvent*>(this->field->get_field()[y][x])) {
                this->exit_event = dynamic_cast<ExitEvent*>(this->field->get_field()[y][x]);
                break;
            }
        }
    }
    delete factory;
}

void Controller::move_player(EnumClass::COMMANDS direction) {
    std::pair<int, int> cur_position = field->get_player_position();
    int first_x = cur_position.first;
    int first_y = cur_position.second;
    if (direction == EnumClass::COMMANDS::LEFT) {
        field->set_player_position(first_x - 1, first_y);
    }
    if (direction == EnumClass::COMMANDS::RIGHT) {
        field->set_player_position(first_x + 1, first_y);
    }
    if (direction == EnumClass::COMMANDS::DOWN) {
        field->set_player_position(first_x, first_y + 1);
    }
    if (direction == EnumClass::COMMANDS::UP) {
        field->set_player_position(first_x, first_y - 1);
    }
    cur_position = field->get_player_position(); //переполучаем координаты игрока с учетом зацикливания карты
    if (first_x != cur_position.first or first_y != cur_position.second) {
        player->increase_step();
    }

    play_event(field->get_field()[cur_position.second][cur_position.first]);
}

void Controller::update_visualization() {
    print_player_info();
    this->field_view->draw_field();
}

void Controller::print_player_info()
{
    std::cout << "Здоровье игрока: " << player->get_health() << '\n';
    std::cout << "Золото игрока: " << player->get_gold() << '\n';
    std::cout << "Отмычки игрока: " << player->get_passkey() << '\n';
    std::cout << "Пройдено шагов: " << player->get_step() << '\n';
}

void Controller::create_logger(std::vector<EnumClass::LogLevels> levels_to_log)
{
    this->logger = new Observer(std::vector<ISubject*>());
    this->logger->add_levels_to_log(levels_to_log);
    this->logger->add_log_printers(log_printers);
}

void Controller::initializing_logger() {
    std::vector<ISubject*> subj = { this->player, this->field };
    for (int x = 0; x < this->field->get_width(); x++) {
        for (int y = 0; y < this->field->get_height(); y++) {
            subj.push_back(this->field->get_field()[y][x]);
        }
    }
    this->logger->add_subjects(subj);
}

void Controller::create_log_printers(std::vector<int> log_printers) {
    for (auto elem : log_printers) {
        switch (elem)
        {
        case 1: {
            this->log_printers.push_back(new TerminalPrinter);
            break;
        }
        case 2: {
            this->log_printers.push_back(new FilePrinter);
            break;
        }
        default:
            break;
        }
    }
}

void Controller::play_event(Cell* cur_cell) {
    IEvent* event = cur_cell->get_event();
    if (event != nullptr) {
        event->attach(this->logger);
        event->React();
        event->detach(this->logger);
        //
        if (dynamic_cast<Boss*>(event)) {
            {
                if (dynamic_cast<Boss*>(event)->is_dead()) {
                    this->exit_event->boss_is_defeat();
                }
            }
        }
        //
        if (event->is_one_time()) {
            cur_cell->set_event(nullptr);
        }
    }
}

DefeatEvent* Controller::get_defeat_event()
{
    return this->defeat_event;
}

ExitEvent* Controller::get_exit_event() {
    return this->exit_event;
}

Observer* Controller::get_logger()
{
    return this->logger;
}

Controller::~Controller() {
    delete field_view;
    delete logger;
    for (int i = 0; i < log_printers.size(); i++) {
        delete log_printers[i];
    }
    delete player;
    delete field;
    delete exit_event;
    delete defeat_event;
}