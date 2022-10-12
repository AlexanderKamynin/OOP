#pragma once
#include "../Player/Player.h"
#include "../Background/Field.h"
#include "../Background/Cell.h"
#include "../Background/FieldView.h"
#include "../EventsFactory/MapEventFactory/MapEventFactory.h"
#include "../EventsFactory/GameProcessEventFactory/GameProcessEventFactory.h"
#include "../EventsFactory/EnemiesEventFactory/EnemiesEventFactory.h"
#include "CommandReader.h"
#include <string>

class Controller {
public:
    Controller();

    void create_field(int height, int width);

    void move_player(CommandReader::COMMANDS direction);

    void update_visualization();

    void print_player_info();

    void create_events();

    void play_event(IEvent* event);

    bool event_is_one_time(IEvent* event);

    DefeatEvent* get_defeat_event();

    ExitEvent* get_exit_event();

    ~Controller();
private:
    Player* player;
    Field* field;
    FieldView* field_view;
    MapEventFactory* map_event_factory;
    EnemiesEventFactory* enemies_event_factory;
    ExitEvent* exit_event;
    DefeatEvent* defeat_event;
};