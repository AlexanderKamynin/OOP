#include "SecondLevel.h"

Field* SecondLevel::generate_level()
{
	FieldGenerator<
		RuleFieldSize<15, 15>,
		RulePlayerSpawn<7, 7>,
		RuleExitSpawn<11, 8>,
		RuleMapEventSpawn<MapEventFactory::MapEventToCreate::TrapEvent, 8>,
		RuleMapEventSpawn<MapEventFactory::MapEventToCreate::CeilingCollapseEvent, 4>,
		RuleEnemiesSpawn<EnemiesEventFactory::EnemyToCreate::RatEnemy,
		std::make_pair(20, 30), std::make_pair(2, 5), std::make_pair(5, 75), 7>,
		RuleEnemiesSpawn<EnemiesEventFactory::EnemyToCreate::WarrionEnemy,
		std::make_pair(30, 50), std::make_pair(7, 12), std::make_pair(100, 150), 7>,
		RuleEnemiesSpawn<EnemiesEventFactory::EnemyToCreate::BossEnemy,
		std::make_pair(50, 60), std::make_pair(12, 15), std::make_pair(500, 1000), 1>,
		RuleObjectSpawn<GameObjectEventFactory::GameObjectToCreate::AltarObject, 2>,
		RuleObjectSpawn<GameObjectEventFactory::GameObjectToCreate::LockedTreasureObject, 5>,
		RuleObjectSpawn<GameObjectEventFactory::GameObjectToCreate::UnlockedTreasureObject, 7>,
		RuleWallSpawn<15>
	> generator;
	return generator.generate();
}
