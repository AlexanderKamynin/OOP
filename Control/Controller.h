#pragma once
#include "../Player/Player.h"
#include "../Background/Field.h"
#include "../Background/Cell.h"
#include "../Background/FieldView.h"
#include "../Events/Trap.h"
#include "CommandReader.h"
#include <string>

class Controller {
public:
    Controller();

    void create_field(int height, int width);

    void move_player(CommandReader::COMMANDS direction);

    void update_visualization();

    ~Controller();
private:
    Player* player;
    Field* field;
    FieldView* field_view;
};