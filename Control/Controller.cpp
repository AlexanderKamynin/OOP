#include "Controller.h"


Controller::Controller() {
    this->field_view = nullptr;
    this->field = nullptr;
    this->player = new Player;
    this->map_event_factory = new MapEventFactory(this->player);
    this->enemies_event_factory = new EnemiesEventFactory(this->player);
    this->game_obj_event_factory = new GameObjectEventFactory(this->player);
    GameProcessEventFactory* factory = new GameProcessEventFactory(this->player);
    this->defeat_event = dynamic_cast<DefeatEvent*>(factory->createDefeatEvent());
    this->exit_event = dynamic_cast<ExitEvent*>(factory->createExitEvent());
    delete factory;
    this->cur_log = new LogGameStatus(std::vector<ISubject*>());
    cur_log->activate();
}

void Controller::create_field(int height, int width) {
    this->field = new Field(height, width);

    //проверочное задание клеткам проходимости
    this->field->get_field()[5][5]->set_passability(false);
    this->field->get_field()[1][0]->set_passability(false);
    this->field->get_field()[2][3]->set_passability(false);
    //
    create_events();
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

    play_event(field->get_field()[cur_position.second][cur_position.first]);
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

void Controller::create_logs()
{
    //std::vector<ISubject*> subj = { this->player, this->field };
    //for (int x = 0; x < this->field->get_width(); x++) {
    //    for (int y = 0; y < this->field->get_height(); y++) {
    //        subj.push_back(this->field->get_field()[y][x]);
    //    }
    //}
    //this->log_game = new LogGame(subj);
}

void Controller::create_events()
{
    //задание выхода
    this->field->get_field()[9][9]->set_event(exit_event);
    //

    //проверочное задание ловушки
    this->field->get_field()[0][1]->set_event(map_event_factory->createTrap());
    this->field->get_field()[0][2]->set_event(map_event_factory->createTrap());
    //

    //обрушение
    std::vector<Cell*> cells_to_change = {
            this->field->get_field()[0][9],
            this->field->get_field()[0][5],
            this->field->get_field()[6][6],
            this->field->get_field()[4][6],
            this->field->get_field()[9][2]
    };
    this->field->get_field()[1][2]->set_event(map_event_factory->createCeilingCollapse(cells_to_change));
    // 

    //создание алтаря
    this->field->get_field()[7][2]->set_event(game_obj_event_factory->createAltar());
    //

    //проверочное задание сокровищ
    this->field->get_field()[5][6]->set_event(game_obj_event_factory->createUnlockedTreasure());
    this->field->get_field()[0][3]->set_event(game_obj_event_factory->createLockedTreasure());
    //

    //проверочное создание врагов
    this->field->get_field()[7][7]->set_event(enemies_event_factory->createRat());
    this->field->get_field()[6][6]->set_event(enemies_event_factory->createWarrion(40, 5, 30, 2));
    this->field->get_field()[8][8]->set_event(enemies_event_factory->createBoss());
    //
}

void Controller::play_event(Cell* cur_cell) {
    IEvent* event = cur_cell->get_event();
    if (event != nullptr) {
        event->attach(this->cur_log);
        event->React();
        event->detach(this->cur_log);
        //
        if (dynamic_cast<Boss*>(event)) {
            {
                if (dynamic_cast<Boss*>(event)->is_dead()) {
                    this->exit_event->boss_is_defeat();
                }
            }
        }
        //
        if (event->is_one_time()) {
            cur_cell->set_event(nullptr);
        }
    }
}

DefeatEvent* Controller::get_defeat_event()
{
    return this->defeat_event;
}

ExitEvent* Controller::get_exit_event() {
    return this->exit_event;
}

IObserver* Controller::get_cur_log()
{
    return this->cur_log;
}

Controller::~Controller() {
    delete field_view;
    delete player;
    delete field;
    delete map_event_factory;
    delete enemies_event_factory;
    delete game_obj_event_factory;
    delete exit_event;
    delete defeat_event;
}