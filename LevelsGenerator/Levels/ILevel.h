#pragma once
#include "../FieldGenerator/FieldGenerator.h"
#include "../../EventsFactory/MapEventFactory/MapEventFactory.h"
#include "../../EventsFactory/EnemiesEventFactory/EnemiesEventFactory.h"
#include "../../EventsFactory/GameObjectEventFactory/GameObjectEventFactory.h"
#include "../../EventsFactory/GameProcessEventFactory/GameProcessEventFactory.h"


class ILevel
{
public:
	virtual Field* generate_level() = 0;
	virtual ~ILevel() = 0 {};
};

