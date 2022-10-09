#pragma once
#include "IEvent.h"
#include "../Player/Player.h"

class MapEvent : public IEvent
{
public:
	MapEvent(Player* player);
protected:
	Player* player;
};
