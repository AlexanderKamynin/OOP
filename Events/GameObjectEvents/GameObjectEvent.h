#pragma once
#include "../IEvent.h"
#include "../../Player/Player.h"


class GameObjectEvent : public IEvent
{
public:
	GameObjectEvent(Player* player);

	virtual ~GameObjectEvent() = 0 {};
protected:
	Player* player;
};

