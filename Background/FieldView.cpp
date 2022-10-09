#include "FieldView.h"


FieldView::FieldView(Field* field) {
    this->field = field;
    this->cell_view = new CellView;
}

void FieldView::draw_field() {
    int height = field->get_height();
    int width = field->get_width();
    std::pair<int, int> player_position = field->get_player_position();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (player_position.first == x && player_position.second == y) {
                std::cout << player_view;
            }
            else {
                cell_view->draw_cell(field->get_field()[y][x]);
            }
        }
        std::cout << '\n';
    }
}

FieldView::~FieldView() {
    delete cell_view;
}