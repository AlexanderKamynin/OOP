#include "MapEventFactory.h"

IEvent* MapEventFactory::createTrap() {
	return new Trap(this->player);
}

IEvent* MapEventFactory::createLockedTreasure(int gold) {
	LockedTreasure* treasure = new LockedTreasure(this->player);
	treasure->set_gold_in_treasure(gold);
	return treasure;
}

IEvent* MapEventFactory::createUnlockedTreasure(int gold) {
	UnlockedTreasure* treasure = new UnlockedTreasure(this->player);
	treasure->set_gold_in_treasure(gold);
	return treasure;
}

IEvent* MapEventFactory::createCeilingCollapse(std::vector<Cell*> cells_to_change)
{
	CeilingCollapse* collapse = new CeilingCollapse(cells_to_change);
	return collapse;
}
