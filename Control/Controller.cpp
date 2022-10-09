#include "Controller.h"


Controller::Controller() {
    this->field_view = nullptr;
    this->field = nullptr;
    this->player = new Player;
}

void Controller::create_field(int height, int width) {
    this->field = new Field(height, width);

    //проверочное задание клеткам проходимости
    this->field->get_field()[5][5]->set_passability(false);
    this->field->get_field()[1][0]->set_passability(false);
    this->field->get_field()[2][3]->set_passability(false);
    //

    //проверочное задание ловушки
    Trap* trap = new Trap(player);
    this->field->get_field()[0][1]->set_event(trap);
    //

    this->field_view = new FieldView(this->field);

}

void Controller::move_player(CommandReader::COMMANDS direction) {
    std::pair<int, int> cur_position = field->get_player_position();
    int new_x = cur_position.first;
    int new_y = cur_position.second;
    if (direction == CommandReader::COMMANDS::LEFT) {
        new_x -= 1;
        field->set_player_position(new_x, new_y);
    }
    if (direction == CommandReader::COMMANDS::RIGHT) {
        new_x += 1;
        field->set_player_position(new_x, new_y);
    }
    if (direction == CommandReader::COMMANDS::DOWN) {
        new_y += 1;
        field->set_player_position(new_x, new_y);
    }
    if (direction == CommandReader::COMMANDS::UP) {
        new_y -= 1;
        field->set_player_position(new_x, new_y);
    }
    cur_position = field->get_player_position(); //переполучаем координаты игрока с учетом зацикливания карты
    play_event(field->get_field()[cur_position.second][cur_position.first]->get_event());
    field->get_field()[cur_position.second][cur_position.first]->set_event(nullptr); //удаление ловушки после ее отработки, в будущем нужно поправить !!!!
    print_player_info();
}

void Controller::update_visualization() {
    this->field_view->draw_field();
}

void Controller::print_player_info()
{
    std::cout << "Здоровье игрока: " << player->get_health() << '\n';
}

void Controller::play_event(IEvent* event) {
    if (event != nullptr) {
        event->React();
    }
}

Controller::~Controller() {
    delete field_view;
    delete player;
    delete field;
}