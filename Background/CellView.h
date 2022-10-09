#pragma once
#include "Cell.h"
#include <iostream>


class CellView {
public:
    CellView() = default;

    void draw_cell(Cell* cell);

    ~CellView() = default;
private:
    char passableCell = '.';
    char impassableCell = 'x';
};