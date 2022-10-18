#pragma once
#include "Cell.h"
#include "../Events/GameObjectEvents/ITreasure/ITreasure.h"
#include "../Events/EnemiesEvents/EnemiesEvents.h"
#include "../Events/GameProcessEvents/ExitEvent/ExitEvent.h"
#include "../Events/GameObjectEvents/Altar/Altar.h"
#include <iostream>


class CellView {
public:
    CellView() = default;

    void draw_cell(Cell* cell);

    ~CellView() = default;
private:
    char passableCell = '.';
    char impassableCell = 'x';
    char treasureCell = 't';
    char enemiesCell = 'e';
    char altarCell = 'A';
    char exitCell = '!';
};