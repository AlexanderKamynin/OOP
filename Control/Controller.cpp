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

    Trap event(this->player);
    this->field->get_field()[3][3]->set_event(&event);

    this->field_view = new FieldView(this->field);

}

void Controller::move_player(CommandReader::COMMANDS direction) {
    if (direction == CommandReader::COMMANDS::LEFT) {
        std::pair<int, int> cur_position = field->get_player_position();
        int new_x = cur_position.first - 1;
        int new_y = cur_position.second;
        field->set_player_position(new_x, new_y);
    }
    if (direction == CommandReader::COMMANDS::RIGHT) {
        std::pair<int, int> cur_position = field->get_player_position();
        int new_x = cur_position.first + 1;
        int new_y = cur_position.second;
        field->set_player_position(new_x, new_y);
    }
    if (direction == CommandReader::COMMANDS::DOWN) {
        std::pair<int, int> cur_position = field->get_player_position();
        int new_x = cur_position.first;
        int new_y = cur_position.second + 1;
        field->set_player_position(new_x, new_y);
    }
    if (direction == CommandReader::COMMANDS::UP) {
        std::pair<int, int> cur_position = field->get_player_position();
        int new_x = cur_position.first;
        int new_y = cur_position.second - 1;
        field->set_player_position(new_x, new_y);
    }
}

void Controller::update_visualization() {
    this->field_view->draw_field();
}


Controller::~Controller() {
    delete field_view;
    delete player;
    delete field;
}