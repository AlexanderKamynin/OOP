#pragma once
#include "../../Background/Field.h"
#include "../Rules/RuleFieldSize.h"
#include "../Rules/RulePlayerSpawn.h"
#include "../Rules/FieldEventsRules/RuleMapEventSpawn.h"
#include "../Rules/FieldEventsRules/RuleExitSpawn.h"
#include "../Rules/EnemiesRules/RuleEnemiesSpawn.h"
#include "../Rules/GameObjectRules/RuleObjectSpawn.h"


template<class... Rules>
class FieldGenerator
{
public:
	Field* generate() {
		Field* field = new Field();
		//����������
		(Rules()(field),...);
		return field;
	}
};

