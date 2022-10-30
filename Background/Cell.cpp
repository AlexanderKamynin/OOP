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
    Message msg(EnumClass::LOG_GAME, "Cell::set_passability()");
    this->notify(msg);
    this->passability = value;
}

IEvent* Cell::get_event()
{
    return this->event;
}

void Cell::set_event(IEvent* event)
{
    Message msg(EnumClass::LOG_GAME, "Cell::set_event()");
    this->notify(msg);
    delete this->event;
    this->event = event;
}

Cell::~Cell() {
    delete this->event;
}
