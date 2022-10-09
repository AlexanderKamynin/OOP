#include "Cell.h"

Cell::Cell(bool passability, IEvent* event)
{
    this->passability = passability;
    this->event = event;
}

void Cell::play_event()
{
    if (this->event != nullptr) {
        this->event->React();
    }
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
