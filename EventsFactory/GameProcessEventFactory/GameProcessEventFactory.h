#pragma once
#include "../IEventFactory.h"
#include "../../Player/Player.h"
#include "../../Events/GameProcessEvents/DefeatEvent/DefeatEvent.h"
#include "../../Events/GameProcessEvents/ExitEvent/ExitEvent.h"


class GameProcessEventFactory : public IEventFactory
{
public:
	GameProcessEventFactory(Player* player) : IEventFactory(player) {};

	IEvent* createExitEvent();

	IEvent* createDefeatEvent();
};