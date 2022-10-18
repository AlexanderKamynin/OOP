#include "MapEvent.h"

MapEvent::MapEvent(Player* player)
{
	this->player = player;
}

MapEvent::MapEvent(std::vector<Cell*> cells_to_change)
{
	this->cells_to_change = cells_to_change;
}
