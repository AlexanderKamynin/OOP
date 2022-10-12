#include "Controller.h"


Controller::Controller() {
    this->field_view = nullptr;
    this->field = nullptr;
    this->player = new Player;
    this->defeat_event = new DefeatEvent(this->player);
    this->exit_event = new ExitEvent();
}

void Controller::create_field(int height, int width) {
    this->field = new Field(height, width);
    this->field->get_field()[9][9]->set_event(exit_event);

    //проверочное задание клеткам проходимости
    this->field->get_field()[5][5]->set_passability(false);
    this->field->get_field()[1][0]->set_passability(false);
    this->field->get_field()[2][3]->set_passability(false);
    //

    //проверочное задание ловушки
    Trap* trap1 = new Trap(player);
    Trap* trap2 = new Trap(player);
    this->field->get_field()[0][1]->set_event(trap1);
    this->field->get_field()[0][2]->set_event(trap2);
    //

    //проверочное задание сокровищ
    UnlockedTreasure* unlocked = new UnlockedTreasure(player);
    LockedTreasure* locked = new LockedTreasure(player);
    unlocked->set_gold_in_treasure(500);
    locked->set_gold_in_treasure(1000);
    this->field->get_field()[5][6]->set_event(unlocked);
    this->field->get_field()[0][3]->set_event(locked);
    //

    //проверочное создание врагов
    Rat* rat = new Rat(player);
    Warrion* warrion = new Warrion(player);
    Boss* boss = new Boss(player);

    rat->set_passkey();
    rat->set_gold(10);
    boss->set_gold(15000);
    
    this->field->get_field()[7][7]->set_event(rat);
    this->field->get_field()[6][6]->set_event(warrion);
    this->field->get_field()[8][8]->set_event(boss);
    //

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
        if (dynamic_cast<Boss*>(event)->is_dead()) {
            this->exit_event->boss_is_defeat();
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
    delete defeat_event;
    delete exit_event;
    delete player;
    delete field;
}