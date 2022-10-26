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
    Message msg("log_game", "set_passability from Cell\n");
    this->notify(msg);
    this->passability = value;
}

IEvent* Cell::get_event()
{
    return this->event;
}

void Cell::set_event(IEvent* event)
{
    Message msg("log_game", "set_event from Cell\n");
    this->notify(msg);
    delete this->event;
    this->event = event;
}

Cell::~Cell() {
    delete this->event;
}
