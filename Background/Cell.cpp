#include "Cell.h"

Cell::Cell(bool passability, IEvent* event)
{
    this->passability = passability;
    this->event = event;
}

bool Cell::get_passability()
{
    return this->passability;
}

void Cell::set_passability(bool value)
{
    this->notify(Message("log_game", "set_passability from Cell\n"));
    this->passability = value;
}

IEvent* Cell::get_event()
{
    return this->event;
}

void Cell::set_event(IEvent* event)
{
    this->notify(Message("log_game", "set_event from Cell\n"));
    delete this->event;
    this->event = event;
}

Cell::~Cell() {
    delete this->event;
}
