#include "Field.h"


Field::Field(int height, int width) { 
    if (height < 10 || height > 30) {
        this->height = 10;
    }
    else {
        this->height = height;
    }

    if (width < 10 || width > 30) {
        this->width = 10;
    }
    else {
        this->width = width;
    }
    for (int y = 0; y < this->height; y++) {
        this->field.push_back(std::vector<Cell*>());
        for (int x = 0; x < this->width; x++) {
            this->field.back().emplace_back(new Cell);
        }
    }
    this->x_player_coordinate = this->y_player_coordinate = 0;
}

Field::Field(const Field& other)
{
    this->height = other.height;
    this->width = other.width;
    this->x_player_coordinate = other.x_player_coordinate;
    this->y_player_coordinate = other.y_player_coordinate;
    for (int y = 0; y < height; y++) {
        this->field.push_back(std::vector<Cell*>(other.field[y]));
        for (int x = 0; x < width; x++) {
            this->field.back().emplace_back(other.field[y][x]);
        }
    }
}

Field::Field(Field&& other)
{
    this->height = other.height;
    this->width = other.width;
    this->field = other.field;
    this->x_player_coordinate = other.x_player_coordinate;
    this->y_player_coordinate = other.y_player_coordinate;

    other.height = other.width = 0;
    other.x_player_coordinate = other.y_player_coordinate = 0;
    other.field = std::vector<std::vector<Cell*>>();
}

Field& Field::operator=(const Field& other)
{
    this->height = other.height;
    this->width = other.width;
    this->x_player_coordinate = other.x_player_coordinate;
    this->y_player_coordinate = other.y_player_coordinate;

    this->field.clear();

    for (int y = 0; y < height; y++) {
        this->field.push_back(std::vector<Cell*>(other.field[y]));
        for (int x = 0; x < width; x++) {
            this->field.back().emplace_back(other.field[y][x]);
        }
    }

    return *this;
}

Field& Field::operator=(Field&& other)
{
    this->field.clear();

    this->height = other.height;
    this->width = other.width;
    this->x_player_coordinate = other.x_player_coordinate;
    this->y_player_coordinate = other.y_player_coordinate;

    for (int y = 0; y < height; y++) {
        this->field.push_back(std::vector<Cell*>(other.field[y]));
        for (int x = 0; x < width; x++) {
            this->field.back().emplace_back(other.field[y][x]);
        }
    }

    other.height = other.width = 0;
    this->x_player_coordinate = this->y_player_coordinate = 0;
    other.field = std::vector<std::vector<Cell*>>();
    return *this;
}

int Field::get_width() {
    return this->width;
}

int Field::get_height() {
    return this->height;
}

std::vector<std::vector<Cell*>> Field::get_field()
{
    return this->field;
}

std::pair<int, int> Field::get_player_position() {
    std::pair<int, int> player_position{ this->x_player_coordinate, this->y_player_coordinate };
    return player_position;
}

void Field::set_player_position(int new_x, int new_y) {
    if (new_x < 0) {
        new_x = width - 1;
    }
    if (new_x >= width) {
        new_x = 0;
    }
    if (new_y < 0) {
        new_y = height - 1;
    }
    if (new_y >= height) {
        new_y = 0;
    }
    if (this->field[new_y][new_x]->get_passability() == true) {
        this->x_player_coordinate = new_x;
        this->y_player_coordinate = new_y;
        Message msg("log_game", "new player position in Field\n");
        this->notify(msg);
    }
    else {
        Message msg("log_error", "player try to step on impassable cell\n");
        this->notify(msg);
        std::cout << "Прохода нет" << '\n';
    }
}

Field::~Field() {
    field.clear();
}