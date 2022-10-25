#pragma once
#include "Cell.h"
#include "../Player/Player.h"
#include "../Logging/Subject.h"
#include <iostream>
#include <vector>

class Field : public Subject
{
public:
    explicit Field(int height = 10, int width = 10);

    Field(const Field& other);

    Field(Field&& other);

    Field& operator = (const Field& other);

    Field& operator = (Field&& other);

    int get_width();

    int get_height();

    std::pair<int, int> get_player_position();

    void set_player_position(int new_x, int new_y);

    std::vector<std::vector<Cell*>> get_field();

    ~Field();

private:
    int x_player_coordinate;
    int y_player_coordinate;
    int width;
    int height;
    std::vector<std::vector<Cell*>> field;
};

