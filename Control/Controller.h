#pragma once
#include "../Player/Player.h"
#include "../Background/Field.h"
#include "../Background/Cell.h"
#include "../Background/FieldView.h"
#include "../Logging/Observer.h"
#include "../Logging/ILogPrinter.h"
#include "../Logging/FilePrinter.h"
#include "../Logging/TerminalPrinter.h"
#include "../LevelsGenerator/LevelContext.h"
#include "../EnumClass.h"
#include <string>


class Controller {
public:
    Controller();

    void create_level(int level);

    void move_player(EnumClass::COMMANDS direction);

    void update_visualization();

    void print_player_info();

    void create_logger(std::vector<EnumClass::LogLevels> levels_to_log);

    void create_log_printers(std::vector<int> log_printers);

    void initializing_logger();

    void play_event(Cell* cur_cell);

    DefeatEvent* get_defeat_event();

    ExitEvent* get_exit_event();

    Observer* get_logger();

    ~Controller();
private:
    Player* player;
    Field* field;
    LevelContext* level_context;
    FieldView* field_view;
    ExitEvent* exit_event;
    DefeatEvent* defeat_event;
    std::vector<ILogPrinter*> log_printers;
    Observer* logger;
};