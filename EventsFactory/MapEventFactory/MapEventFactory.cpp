#include "MapEventFactory.h"

IEvent* MapEventFactory::createTrap() {
	return new Trap(this->player);
}

IEvent* MapEventFactory::createCeilingCollapse(std::vector<Cell*> cells_to_change)
{
	CeilingCollapse* collapse = new CeilingCollapse(cells_to_change);
	return collapse;
}
