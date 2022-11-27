#pragma once
#include "../../Background/Field.h"
#include "../Rules/RuleFieldSize.h"
#include "../Rules/RulePlayerSpawn.h"
#include "../Rules/MapEventsRules/RuleTrapSpawn.h"


template<class... Rules>
class FieldGenerator
{
public:
	Field* generate() {
		Field* field = new Field;
		//распаковка
		(Rules()(field),...);
		return field;
	}
};

