#include "CellView.h"


void CellView::draw_cell(Cell* cell) {
    bool passability = cell->get_passability();
    if (passability) {
        std::cout << passableCell;
    }
    else {
        std::cout << impassableCell;
    }
}