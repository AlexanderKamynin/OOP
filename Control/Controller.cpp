#include "Controller.h"


Controller::Controller() {
    this->field_view = nullptr;
    this->field = nullptr;
    this->player = new Player;
    this->map_event_factory = new MapEventFactory(this->player);
    this->enemies_event_factory = new EnemiesEventFactory(this->player);
    GameProcessEventFactory* factory = new GameProcessEventFactory(this->player);
    this->defeat_event = dynamic_cast<DefeatEvent* >(factory->createDefeatEvent());
    this->exit_event = dynamic_cast<ExitEvent*>(factory->createExitEvent());
    delete factory;
}

void Controller::create_field(int height, int width) {
    this->field = new Field(height, width);

    //проверочное задание клеткам проходимости
    this->field->get_field()[5][5]->set_passability(false);
    this->field->get_field()[1][0]->set_passability(false);
    this->field->get_field()[2][3]->set_passability(false);
    //
    create_events();
    this->field_view = new FieldView(this->field);
}

void Controller::move_player(CommandReader::COMMANDS direction) {
    std::pair<int, int> cur_position = field->get_player_position();
    int first_x = cur_position.first;
    int first_y = cur_position.second;

    if (direction == CommandReader::COMMANDS::LEFT) {
        field->set_player_position(first_x - 1, first_y);
    }
    if (direction == CommandReader::COMMANDS::RIGHT) {
        field->set_player_position(first_x + 1, first_y);
    }
    if (direction == CommandReader::COMMANDS::DOWN) {
        field->set_player_position(first_x, first_y + 1);
    }
    if (direction == CommandReader::COMMANDS::UP) {
        field->set_player_position(first_x, first_y - 1);
    }
    cur_position = field->get_player_position(); //переполучаем координаты игрока с учетом зацикливания карты
    if (first_x != cur_position.first or first_y != cur_position.second) {
        player->increase_step();
    }

    IEvent* event = field->get_field()[cur_position.second][cur_position.first]->get_event();
    play_event(event);
    if (event_is_one_time(event)){
        delete event;
        field->get_field()[cur_position.second][cur_position.first]->set_event(nullptr);
    }
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

void Controller::create_events() {
    //задание выхода
    this->field->get_field()[9][9]->set_event(exit_event);
    //

    // 
    //проверочное задание ловушки
    this->field->get_field()[0][1]->set_event(map_event_factory->createTrap());
    this->field->get_field()[0][2]->set_event(map_event_factory->createTrap());
    //

    //проверочное задание сокровищ
    this->field->get_field()[5][6]->set_event(map_event_factory->createUnlockedTreasure());
    this->field->get_field()[0][3]->set_event(map_event_factory->createLockedTreasure());
    //

    //проверочное создание врагов
    this->field->get_field()[7][7]->set_event(enemies_event_factory->createRat());
    this->field->get_field()[6][6]->set_event(enemies_event_factory->createWarrion());
    this->field->get_field()[8][8]->set_event(enemies_event_factory->createBoss());
    //
}

void Controller::play_event(IEvent* event) {
    if (event != nullptr) {
        event->React();
    }
}

bool Controller::event_is_one_time(IEvent* event)
{
    if (dynamic_cast<Trap*>(event) or dynamic_cast<UnlockedTreasure*>(event)) {
        return true;
    }
    if (dynamic_cast<LockedTreasure*>(event)) {
        return dynamic_cast<LockedTreasure*>(event)->is_unlock();
    }
    if (dynamic_cast<EnemiesEvents*>(event)) {
        if (dynamic_cast<Boss*>(event)) {
            if (dynamic_cast<Boss*>(event)->is_dead()) {
                this->exit_event->boss_is_defeat();
            }
        }
        return dynamic_cast<EnemiesEvents*>(event)->is_dead();
    }
    return false;
}

DefeatEvent* Controller::get_defeat_event()
{
    return this->defeat_event;
}

ExitEvent* Controller::get_exit_event() {
    return this->exit_event;
}

Controller::~Controller() {
    delete field_view;
    delete player;
    delete field;
    delete map_event_factory;
    delete enemies_event_factory;
    delete exit_event;
    delete defeat_event;
}