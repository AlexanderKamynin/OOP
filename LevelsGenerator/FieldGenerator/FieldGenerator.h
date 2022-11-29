#pragma once
#include "../../Background/Field.h"
#include "../Rules/RuleFieldSize.h"
#include "../Rules/RulePlayerSpawn.h"
#include "../Rules/RuleMapEventSpawn.h"
#include "../Rules/RuleExitSpawn.h"
#include "../Rules/RuleEnemiesSpawn.h"
#include "../Rules/RuleObjectSpawn.h"
#include "../Rules/RuleWallSpawn.h"


template<class... Rules>
class FieldGenerator
{
public:
	Field* generate() {
		Field* field = new Field();
		//распаковка
		(Rules()(field),...);
		return field;
	}
};

