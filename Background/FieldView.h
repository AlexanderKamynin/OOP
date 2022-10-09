#pragma once
#include "Field.h"
#include "CellView.h"

class FieldView {
public:
    FieldView(Field* field);

    void draw_field();

    ~FieldView();

private:
    Field* field;
    CellView* cell_view;
    char player_view = 'P';
};