#pragma once
#include "../IEvent.h"
#include "../../Player/Player.h"
#include "../../Background/Cell.h"
#include <vector>


class MapEvent : public IEvent
{
public:
	MapEvent(Player* player);

	MapEvent(std::vector<Cell*> cells_to_change);

	virtual ~MapEvent() = 0 {};
protected:
	Player* player;
	std::vector<Cell*> cells_to_change;
};
