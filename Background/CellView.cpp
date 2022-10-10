#include "CellView.h"


void CellView::draw_cell(Cell* cell) {
    bool passability = cell->get_passability();
    if (passability) {
        if (dynamic_cast<ITreasure*>(cell->get_event())) {
            std::cout << treasureCell;
        }
        else {
            std::cout << passableCell;
        }
    }
    else {
        std::cout << impassableCell;
    }
}