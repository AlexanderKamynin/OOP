#pragma once
#include "../Events/IEvent.h"


class Cell
{
public:
    Cell(bool passability = true, IEvent* event = nullptr);

    bool get_passability();

    void set_passability(bool value);

    IEvent* get_event();

    void set_event(IEvent* event);

    ~Cell() = default;
private:
    IEvent* event; //указатель на событие
    bool passability; //проходимость клетки
};