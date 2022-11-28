#pragma once
#include "../IEventFactory.h"
#include "../../Background/Field.h"
#include "../../Events/MapEvents/Trap/Trap.h"
#include "../../Events/MapEvents/CeilingCollapse/CeilingCollapse.h"


class MapEventFactory : public IEventFactory
{
public:
	MapEventFactory(Field* field) : IEventFactory(field) {};
	
	enum MapEventToCreate {
		TrapEvent,
		CeilingCollapseEvent
	};

	IEvent* createMapEvent(MapEventToCreate event_to_create);
private:
	IEvent* createTrap();

	IEvent* createCeilingCollapse();
};
