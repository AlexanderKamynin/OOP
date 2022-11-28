#pragma once
#include "../IEventFactory.h"
#include "../../Background/Field.h"
#include "../../Events/GameProcessEvents/DefeatEvent/DefeatEvent.h"
#include "../../Events/GameProcessEvents/ExitEvent/ExitEvent.h"


class GameProcessEventFactory : public IEventFactory
{
public:
	GameProcessEventFactory(Field* field) : IEventFactory(field) {};

	IEvent* createExitEvent();

	IEvent* createDefeatEvent();
};