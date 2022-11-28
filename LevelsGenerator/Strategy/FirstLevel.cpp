#include "FirstLevel.h"

Field* FirstLevel::generate_level()
{
	FieldGenerator<
		RuleFieldSize<10, 10>,
		RulePlayerSpawn<3, 6>,
		RuleExitSpawn<GameProcessEventFactory, 7, 8>,
		RuleMapEventSpawn<MapEventFactory::MapEventToCreate::TrapEvent, 14, 4>,
		RuleMapEventSpawn<MapEventFactory::MapEventToCreate::CeilingCollapseEvent, 26, 2>
	> generator;
	return generator.generate();
}
