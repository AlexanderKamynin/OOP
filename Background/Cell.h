#pragma once
#include "../Events/IEvent.h"
#include "../Logging/Subject.h"


class Cell : public Subject
{
public:
    Cell(bool passability = true, IEvent* event = nullptr);

    bool get_passability();

    void set_passability(bool value);

    IEvent* get_event();

    void set_event(IEvent* event);

    ~Cell();
private:
    IEvent* event; //указатель на событие
    bool passability; //проходимость клетки
};