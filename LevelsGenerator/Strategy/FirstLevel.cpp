#include "FirstLevel.h"

Field* FirstLevel::generate_level()
{
	FieldGenerator<
		RuleFieldSize<10, 10>,
		RulePlayerSpawn<3, 6>,
		RuleTrapSpawn<MapEventFactory, 14, 6>
	> generator;
	return generator.generate();
}
