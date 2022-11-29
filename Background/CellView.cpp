#include "CellView.h"
#include "../Events/MapEvents/Trap/Trap.h"
#include "../Events/MapEvents/CeilingCollapse/CeilingCollapse.h"


void CellView::draw_cell(Cell* cell) {
    bool passability = cell->get_passability();
    if (passability) {
        if (dynamic_cast<ITreasure*>(cell->get_event())) {
            std::cout << treasureCell;
        }
        else if (dynamic_cast<Altar*>(cell->get_event())) {
            std::cout << altarCell;
        }
        else if (dynamic_cast<EnemiesEvents*>(cell->get_event())) {
            std::cout << enemiesCell;
        }
        /*проверка создания ловушек на карте*/
        //else if (dynamic_cast<Trap*>(cell->get_event())) {
        //    std::cout << "Ы";
        //}
        //else if (dynamic_cast<CeilingCollapse*>(cell->get_event())) {
        //    std::cout << "Ъ";
        //}
        else if (dynamic_cast<ExitEvent*>(cell->get_event())) {
            if (dynamic_cast<ExitEvent*>(cell->get_event())->is_show()) {
                std::cout << exitCell;
            }
            else {
                std::cout << passableCell;
            }
        }
        else {
            std::cout << passableCell;
        }
    }
    else {
        std::cout << impassableCell;
    }
}