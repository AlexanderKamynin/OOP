#pragma once
#include "../IEventFactory.h"
#include "../../Player/Player.h"
#include "../../Events/GameObjectEvents/ITreasure/LockedTreasure.h"
#include "../../Events/GameObjectEvents/ITreasure/UnlockedTreasure.h"
#include "../../Events/GameObjectEvents/Altar/Altar.h"


class GameObjectEventFactory : public IEventFactory
{
public:
	GameObjectEventFactory(Player* player) : IEventFactory(player) {};

	IEvent* createAltar();

	IEvent* createLockedTreasure(int gold = 100);

	IEvent* createUnlockedTreasure(int gold = 100);
};

