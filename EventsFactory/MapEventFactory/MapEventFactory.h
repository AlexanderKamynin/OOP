#pragma once
#include "../IEventFactory.h"
#include "../../Player/Player.h"
#include "../../Events/MapEvents/Trap/Trap.h"
#include "../../Events/MapEvents/CeilingCollapse/CeilingCollapse.h"


class MapEventFactory : public IEventFactory
{
public:
	MapEventFactory(Player* player) : IEventFactory(player) {};
	
	IEvent* createTrap();

	IEvent* createCeilingCollapse(std::vector<Cell*> cells_to_change);
};
