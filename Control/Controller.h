#pragma once
#include "../Player/Player.h"
#include "../Background/Field.h"
#include "../Background/Cell.h"
#include "../Background/FieldView.h"
#include "../Events/MapEvents/Trap/Trap.h"
#include "../Events/MapEvents/ITreasure/LockedTreasure.h"
#include "../Events/MapEvents/ITreasure/UnlockedTreasure.h"
#include "../Events/EnemiesEvents/Rat/Rat.h"
#include "CommandReader.h"
#include <string>

class Controller {
public:
    Controller();

    void create_field(int height, int width);

    void move_player(CommandReader::COMMANDS direction);

    void update_visualization();

    void print_player_info();

    void play_event(IEvent* event);

    bool event_is_one_time(IEvent* event);

    ~Controller();
private:
    Player* player;
    Field* field;
    FieldView* field_view;
};