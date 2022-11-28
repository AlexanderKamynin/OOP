#pragma once
#include "../../Background/Field.h"
#include "../Rules/RuleFieldSize.h"
#include "../Rules/RulePlayerSpawn.h"
#include "../Rules/FieldEventsRules/RuleTrapSpawn.h"
#include "../Rules/FieldEventsRules/RuleExitSpawn.h"


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

