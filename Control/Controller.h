#pragma once
#include "../Player/Player.h"
#include "../Background/Field.h"
#include "../Background/Cell.h"
#include "../Background/FieldView.h"
#include "../EventsFactory/MapEventFactory/MapEventFactory.h"
#include "../EventsFactory/GameProcessEventFactory/GameProcessEventFactory.h"
#include "../EventsFactory/EnemiesEventFactory/EnemiesEventFactory.h"
#include "../EventsFactory/GameObjectEventFactory/GameObjectEventFactory.h"
#include "../Logging/LogGame.h"
#include "../Logging/LogError.h"
#include "../Logging/LogGameStatus.h"
#include "../Logging/FilePrinter.h"
#include "../Logging/TerminalPrinter.h"
#include "../Logging/TermFilePrinter.h"
#include "../EnumClass.h"
#include <string>

class Controller {
public:
    Controller();

    void create_field(int height, int width);

    void move_player(EnumClass::COMMANDS direction);

    void update_visualization();

    void print_player_info();

    void create_logs(int log_level = 0);

    void create_log_printer(std::string printer);

    void initializing_logs();

    void create_events();

    void play_event(Cell* cur_cell);

    DefeatEvent* get_defeat_event();

    ExitEvent* get_exit_event();

    IObserver* get_cur_log();

    ~Controller();
private:
    int log_level;
    Player* player;
    Field* field;
    FieldView* field_view;
    MapEventFactory* map_event_factory;
    EnemiesEventFactory* enemies_event_factory;
    GameObjectEventFactory* game_obj_event_factory;
    ExitEvent* exit_event;
    DefeatEvent* defeat_event;
    ILogPrinter* log_printer;
    IObserver* cur_log;
};