#pragma once
#include "../IEventFactory.h"
#include "../../Player/Player.h"
#include "../../Events/GameObjectEvents/ITreasure/LockedTreasure.h"
#include "../../Events/GameObjectEvents/ITreasure/UnlockedTreasure.h"
#include "../../Events/GameObjectEvents/Altar/Altar.h"


class GameObjectEventFactory : public IEventFactory
{
public:
	GameObjectEventFactory(Field* field) : IEventFactory(field) {};

	enum GameObjectToCreate {
		AltarObject,
		LockedTreasureObject,
		UnlockedTreasureObject
	};

	IEvent* createGameObject(GameObjectToCreate object_to_create);

private:
	IEvent* createAltar();

	IEvent* createLockedTreasure();

	IEvent* createUnlockedTreasure();
};

