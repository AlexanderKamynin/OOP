#pragma once
#include "../IEventFactory.h"
#include "../../Player/Player.h"
#include "../../Events/MapEvents/Trap/Trap.h"
#include "../../Events/MapEvents/ITreasure/LockedTreasure.h"
#include "../../Events/MapEvents/ITreasure/UnlockedTreasure.h"
#include "../../Events/MapEvents/CeilingCollapse/CeilingCollapse.h"


class MapEventFactory : public IEventFactory
{
public:
	MapEventFactory(Player* player) : IEventFactory(player) {};
	
	IEvent* createTrap();

	IEvent* createLockedTreasure(int gold = 100);

	IEvent* createUnlockedTreasure(int gold = 100);

	IEvent* createCeilingCollapse(std::vector<Cell*> cells_to_change);
};
