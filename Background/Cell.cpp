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
    this->passability = value;
}

IEvent* Cell::get_event()
{
    return this->event;
}

void Cell::set_event(IEvent* event)
{
    this->event = event;
}
